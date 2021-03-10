#include "wisdom_atd.h"
#include "proverb_atd.h"
#include "aphorism_atd.h"
#include "riddle_atd.h"

using namespace std;
namespace simple_wisdom
{
	// ¬вод параметров обобщенной мудрости
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
		case 3:
			wd = new riddle;
			break;
		default:
			return 0;
		}

		ifst.getline(wd->content, 200);
		ifst >> k;
		ifst.get(tmp);
		wd->mark = k;
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

	void wisdom::Out(ofstream& ofst)
	{
		ofst << content << endl << "ќценка: " << mark << endl;
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