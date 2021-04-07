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

	//Вывод параметров загадки
	void riddle::Out(ofstream& ofst)
	{
		ofst << "Загадка: " << content << endl << "Ответ: " << answer << endl;
	}

	void riddle::MultiMethod(wisdom* other, ofstream& ofst)
	{
		other->MM_Riddle(ofst);
	}

	void riddle::MM_Proverb(ofstream& ofst)
	{
		ofst << "Пословица и Загадка" << endl;
	}

	void riddle::MM_Aphorism(ofstream& ofst)
	{
		ofst << "Афоризм и Загадка" << endl;
	}

	void riddle::MM_Riddle(ofstream& ofst)
	{
		ofst << "Загадка и Загадка" << endl;
	}
}