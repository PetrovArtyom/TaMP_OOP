#include "aphorism_atd.h"
using namespace std;
namespace simple_wisdom
{
	//Ввод параметров афоризма
	void aphorism::InData(ifstream& ifst)
	{
		ifst.getline(author, 50);
	}

	//Вывод параметров афоризма
	void aphorism::Out(ofstream& ofst)
	{
		ofst << "Автор: " << author << endl << "Афоризм: ";
		wisdom::Out(ofst);
	}
}