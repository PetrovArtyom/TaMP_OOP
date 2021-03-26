#include "riddle_atd.h"
using namespace std;
namespace simple_wisdom
{
	//Ввод параметров загадки
	void riddle::InData(ifstream& ifst)
	{
		ifst.getline(answer, 50);
	}

	// Вывод параметров загадки
	void riddle::Out(ofstream& ofst)
	{
		ofst << "Ответ: " << answer << endl << "Загадка: ";
		wisdom::Out(ofst);
	}
}