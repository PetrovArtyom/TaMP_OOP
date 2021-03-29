#include "aphorism_atd.h"
#include <iostream>

using namespace std;
namespace simple_wisdom
{
	//Ввод параметров афоризма из потока
	int aphorism::InData(ifstream& ifst)
	{
		// Чтение строки
		ifst.getline(author, 50);

		// Проверка строки на непустоту
		if (author[0] == '\0')
		{
			cout << endl << "Error! Field author is empty. Please check input file." << endl;
			return 1;
		}
		return 0;
	}

	//Вывод параметров афоризма
	void aphorism::Out(ofstream& ofst)
	{
		ofst << "Автор: " << author << endl << "Афоризм: ";
		wisdom::Out(ofst);
	}
}