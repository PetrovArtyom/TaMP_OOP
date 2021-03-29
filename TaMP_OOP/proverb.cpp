#include "proverb_atd.h"
#include <iostream>

using namespace std;
namespace simple_wisdom
{
	// Ввод параметров пословицы из потока
	int proverb::InData(ifstream& ifst)
	{
		// Чтение строки
		ifst.getline(country, 50);

		// Проверка строки на непустоту
		if (country[0] == '\0')
		{
			cout << endl << "Error! Field country is empty. Please check input file." << endl;
			return 1;
		}
		return 0;
	}

	// Вывод параметров пословицы
	void proverb::Out(ofstream& ofst)
	{
		ofst << "Страна: " << country << endl << "Пословица: ";
		wisdom::Out(ofst);
	}

	// Фильтрованный вывод пословицы
	void proverb::Out_proverb(ofstream& ofst)
	{
		ofst << "Страна: " << country << endl << "Пословица: " << content << endl << "Оценка: " << mark << endl << "Знаков препинания: " << marks_number() << endl << endl;
	}
}
