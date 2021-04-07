#include "proverb_atd.h"
using namespace std;
namespace simple_wisdom
{
	// Ввод параметров пословиц
	void proverb::InData(ifstream& ifst)
	{
		ifst.getline(content, 200);
		ifst.getline(country, 50);
	}

	// Вывод параметров пословиц
	void proverb::Out(ofstream& ofst)
	{
		ofst << "Пословица: " << content << endl << "Страна: " << country << endl;
	}

	void proverb::MultiMethod(wisdom* other, ofstream& ofst)
	{
		other->MM_Proverb(ofst);
	}

	void proverb::MM_Aphorism(ofstream& ofst)
	{
		ofst << "Афоризм и Пословица" << endl;
	}

	void proverb::MM_Proverb(ofstream& ofst)
	{
		ofst << "Пословица и Пословица" << endl;
	}
}
