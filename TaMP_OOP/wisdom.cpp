#include "wisdom_atd.h"
#include "proverb_atd.h"
#include "aphorism_atd.h"
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

	void wisdom::Out(ofstream& ofst)
	{
		ofst << content << endl << "ќценка: " << mark << endl << endl;
	}
}