#include "riddle_atd.h"
#include <iostream>

using namespace std;
namespace simple_wisdom
{
	//Ввод параметров загадки из потока
	int riddle::InData(ifstream& ifst)
	{
		//Чтение строки
		ifst.getline(answer, 50);
		
		// Проверка строки на непустоту
		if (answer[0] == '\0')
		{
			cout << endl << "Error! Field answer is empty. Please check input file." << endl;
			return 1;
		}
		return 0;
	}

	// Вывод параметров загадки в поток
	void riddle::Out(ofstream& ofst)
	{
		ofst << "Ответ: " << answer << endl << "Загадка: ";
		wisdom::Out(ofst);
	}
}