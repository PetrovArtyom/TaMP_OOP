#include "riddle_atd.h"
using namespace std;
namespace simple_wisdom
{
	//Ввод параметров загадки
	void riddle::InData(ifstream& ifst)
	{
		ifst.getline(content, 200);
		ifst.getline(answer, 50);
	}

	//Вывод параметров афоризма
	void riddle::Out(ofstream& ofst)
	{
		ofst << "Загадка: " << content << endl << "Ответ: " << answer << endl << endl;
	}
}