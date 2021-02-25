#include "wisdom_atd.h"
#include "proverb_atd.h"
#include "aphorism_atd.h"
using namespace std;
namespace simple_wisdom
{
	// Ввод параметров обобщенной мудрости
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
			wd->mark = rand() % 10;
			break;
		case 2:
			wd = new aphorism;
			wd->mark = rand() % 10;
			break;
		default:
			return 0;
		}
		wd->InData(ifst);
		return wd;
	}
}