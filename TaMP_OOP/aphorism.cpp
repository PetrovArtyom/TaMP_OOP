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

	//Вывод параметров афоризма
	void aphorism::Out(ofstream& ofst)
	{
		ofst << "Афоризм: " << content << endl << "Автор: " << author << endl << "Оценка: " << mark << endl << endl;
	}
}