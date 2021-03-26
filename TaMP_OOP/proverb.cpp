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
		ofst << "Страна: " << country << endl << "Пословица: ";
		wisdom::Out(ofst);
	}

	void proverb::Out_proverb(ofstream& ofst)
	{
		ofst << "Страна: " << country << endl << "Пословица: " << content << endl << "Оценка: " << mark << endl << "Знаков препинания: " << marks_number() << endl << endl;
	}
}
