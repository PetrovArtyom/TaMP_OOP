#include "wisdom_atd.h"
// Необходима подключить информацию обо всех имеющихся
// геометрических фигурах
#include "proverb_atd.h"
#include "aphorism_atd.h"
using namespace std;
namespace simple_wisdom
{
	// Ввод параметров обобщенной фигуры
	wisdom* wisdom::In(ifstream& ifst)
	{
		wisdom* wd;
		int k;
		ifst >> k;
		char tmp;
		ifst.get(tmp);
		switch (k)
		{
		case 1:
			wd = new proverb;
			break;
		case 2:
			wd = new aphorism;
			break;
		default:
			return 0;
		}
		wd->InData(ifst);
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
}