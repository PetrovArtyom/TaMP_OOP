#include "wisdom_atd.h"
#include "proverb_atd.h"
#include "aphorism_atd.h"
#include "riddle_atd.h"
#include <iostream>

using namespace std;
namespace simple_wisdom
{
	// ���� ���������� ���������� �������� �� ������
	wisdom* wisdom::In(ifstream& ifst)
	{
		// ���������� ��������� �� ��������
		wisdom* wd;

		// ���������� ���� ��������
		char k;
		ifst >> k;

		// �������� ������� �� �������������� � ������
		if ((int)k > 57 || (int)k < 48)			
		{
			cout << endl << "Error! Incorrect input of wisdom type. Please check input file." << endl;
			return 0;
		}

		// ��������������� char � int
		int wd_type = (int)k - 48;				
												
		// ���������� ����������� ������� \n
		char tmp;
		ifst.get(tmp);

		// �������� ������� ���������������� ����
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

		// ���� ������� ������ ��������� �������� - ����������
		ifst.getline(wd->content, 200);

		//�������� ��������� ������
		if (wd->content[0] == '\0')
		{
			cout << endl << "Error! Incorrect input of wisdom type. Please check input file." << endl;
			return 0;
		}
		
		// ���� ������� ������ ��������� �������� - ������
		char str[4];
		ifst.getline(str, 4);

		// �������� ����, ��� ������ �������� ������
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

		// �������� �� ���������� ������� ������ ��������� - ������
		if (count == 0)
		{
			cout << endl << "Error! Incorrect input of wisdom type. Please check input file." << endl;
			return 0;
		}

		// ����������� ������ � ����� 
		int mark = atoi(str);

		ifst.get(tmp);

		// ������ ����������� ������ � ��������������� ���� �������
		wd->mark = mark;
		
		// �������� ���������� ����� ��������������� ���������
		if (wd->InData(ifst) == 1)
		{
			return 0;
		}
		return wd;
	}

	//   ���������� ���������� ������ ����������
	int wisdom::Marks_number()
	{
		// ����� ������ ����������
		int marks_num = 0;

		// ����������� �����
		char marks[] = { '.', ',', '!', '?', '-', ';', ':' };

		// ����� ������� ����������� ������
		int marks_len = 7;

		// ���� ��������
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

	// ����� ���������� ������� �������� � �����
	void wisdom::Out(ofstream& ofst)
	{
		ofst << content << endl << "������: " << mark << endl;
	}

	// ������������� ����� ���������� ������� �������� � �����
	void wisdom::Out_proverb(ofstream& ofst)
	{
		;
	}

	// ��������� ����� "������" ���� ��������
	bool wisdom::Compare(wisdom* a)
	{
		return Marks_number() > a->Marks_number();
	}
}