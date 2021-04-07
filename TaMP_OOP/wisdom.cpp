#include "wisdom_atd.h"
#include "proverb_atd.h"
#include "aphorism_atd.h"
#include "riddle_atd.h"
#include <iostream>

using namespace std;
namespace simple_wisdom
{
	// Ввод параметров обобщенной мудрости из потока
	wisdom* wisdom::In(ifstream& ifst)
	{
		// Объявление указателя на мудрость
		wisdom* wd;

		// Считывание типа мудрости
		char k;
		ifst >> k;

		// Проверка символа на принадлежность к цифрам
		if ((int)k > 57 || (int)k < 48)			
		{
			cout << endl << "Error! Incorrect input of wisdom type. Please check input file." << endl;
			return 0;
		}

		// Конвертирование char в int
		int wd_type = (int)k - 48;				
												
		// Считывание оставшегося символа \n
		char tmp;
		ifst.get(tmp);

		// Создание объекта соответствующего типа
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

		// Ввод первого общего параметра мудрости - содержания
		ifst.getline(wd->content, 200);

		//Проверка непустоты строки
		if (wd->content[0] == '\0')
		{
			cout << endl << "Error! Incorrect input of wisdom type. Please check input file." << endl;
			return 0;
		}
		
		// Ввод второго общего параметра мудрости - оценки
		char str[4];
		ifst.getline(str, 4);

		// Проверка того, что оценка является числом
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

		// Проверка на невведение второго общего параметра - оценки
		if (count == 0)
		{
			cout << endl << "Error! Incorrect input of wisdom type. Please check input file." << endl;
			return 0;
		}

		// Конвертация строки в число 
		int mark = atoi(str);

		ifst.get(tmp);

		// Запись проверенной оценки в соответствующее поле объекта
		wd->mark = mark;
		
		// Проверка успешности ввода индивидуального параметра
		if (wd->InData(ifst) == 1)
		{
			return 0;
		}
		return wd;
	}

	//   Вычисление количества знаков препинания
	int wisdom::Marks_number()
	{
		// Число знаков препинания
		int marks_num = 0;

		// Учитываемые знаки
		char marks[] = { '.', ',', '!', '?', '-', ';', ':' };

		// Длина массива учитываемых знаков
		int marks_len = 7;

		// Цикл подсчёта
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

	// Вывод параметров текущей мудрости в поток
	void wisdom::Out(ofstream& ofst)
	{
		ofst << content << endl << "Оценка: " << mark << endl;
	}

	// Фильтрованный вывод параметров текущей мудрости в поток
	void wisdom::Out_proverb(ofstream& ofst)
	{
		;
	}

	// Сравнение полей "оценка" двух объектов
	bool wisdom::Compare(wisdom* a)
	{
		return Marks_number() > a->Marks_number();
	}
}