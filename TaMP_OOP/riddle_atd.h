#ifndef __riddle_atd__
#define __riddle_atd__
// Требуется описание класса wisdom
#include "wisdom_atd.h"
namespace simple_wisdom
{
	// загадка
	class riddle : public wisdom
	{
	public:
		char answer[50];
		// переопределяем интерфейс класса
		int InData(ifstream& ifst); // ввод
		void Out(ofstream& ofst); // вывод
		riddle() {} // создание без инициализации.
	};
}
#endif