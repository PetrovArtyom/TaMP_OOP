#include "wisdom_atd.h"
#include "proverb_atd.h"
#include "aphorism_atd.h"
#include "riddle_atd.h"
#include <iostream>

using namespace std;
namespace simple_wisdom
{
	// Ввод параметров обобщенной мудрости
	wisdom* wisdom::In(ifstream& ifst)
	{
		wisdom* wd;
		char k;
		ifst >> k;
		if ((int)k > 57 || (int)k < 48)			// Проверяем, что считанный символ - цифра от 0 до 9
		{
			cout << endl << "Error! Incorrect input of wisdom type. Please check input file." << endl;
			return 0;
		}

		// Переводим char в int
		int wd_type = (int)k - 48;				
												
		// Читаем оставшийся \n
		char tmp;
		ifst.get(tmp);

		switch (wd_type)
		{
		case 1:
			wd = new proverb;
			break;
		case 2:
			wd = new aphorism;
			break;
		case 3:
			wd = new riddle;
			break;
		default:
			cout << endl << "Error! Invalid wisdom type entered. Please check input file.";
			return 0;
		}

		ifst.getline(wd->content, 200);

		if (wd->content[0] == '\0')
		{
			cout << endl << "Error! Incorrect input of wisdom type. Please check input file." << endl;
			return 0;
		}
		
		// Читаем строку, предназначенную для оценки
		char str[4];
		ifst.getline(str, 4);

		// Проверяем, что все символы строки - цифры
		int count = 0;
		while (str[count] != '\n' && str[count] != '\0' && count < 4)
		{
			if ((int)str[count] > 57 || (int)str[count] < 48)
			{
				cout << endl << "Error! Incorrect input of wisdom type. Please check input file." << endl;
				return 0;
			}
			count++;
		}

		if (count == 0)
		{
			cout << endl << "Error! Incorrect input of wisdom type. Please check input file." << endl;
			return 0;
		}

		// Переводим строку в int 
		int mark = atoi(str);
		ifst.get(tmp);
		wd->mark = mark;
		if (wd->InData(ifst) == 1)
		{
			return 0;
		}
		return wd;
	}

	int wisdom::marks_number()
	{
		int marks_num = 0;
		char marks[] = { '.', ',', '!', '?', '-', ';', ':' };
		int marks_len = 7;

		for (int i = 0; i < strlen(content); i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (content[i] == marks[j])
				{
					marks_num++;
				}
			}
		}

		return marks_num;
	}

	void wisdom::Out(ofstream& ofst)
	{
		ofst << content << endl << "Оценка: " << mark << endl;
	}

	bool wisdom::compare(wisdom* a)
	{
		return marks_number() > a->marks_number();
	}

	void wisdom::Out_proverb(ofstream& ofst)
	{
		;
	}
}