#include "proverb_atd.h"
using namespace std;
namespace simple_wisdom
{
	// Ввод параметров пословиц
	void proverb::InData(ifstream& ifst)
	{
		ifst.getline(country, 50);
	}

	// Вывод параметров пословиц
	void proverb::Out(ofstream& ofst)
	{
		ofst << "Автор: " << country << endl << "Пословица: ";
		wisdom::Out(ofst);
	}
}
