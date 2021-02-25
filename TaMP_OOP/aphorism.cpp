#include "aphorism_atd.h"
using namespace std;
namespace simple_wisdom
{
	//Ввод параметров афоризма
	void aphorism::InData(ifstream& ifst)
	{
		ifst.getline(content, 200);
		ifst.getline(author, 50);
	}

	int aphorism::marks_number()
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

	//Вывод параметров афоризма
	void aphorism::Out(ofstream& ofst)
	{
		ofst << "Афоризм: " << content << endl << "Автор: " << author << endl;
	}
}