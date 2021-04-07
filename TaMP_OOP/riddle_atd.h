#ifndef __riddle_atd__
#define __riddle_atd__
// Требуется описание класса wisdom
#include "wisdom_atd.h"
namespace simple_wisdom
{
	// загадка
	class riddle : public wisdom
	{
		char answer[50];
	public:
		// переопределяем интерфейса класса
		void InData(ifstream& ifst); // ввод
		void Out(ofstream& ofst); // вывод
		riddle() {} // создание без инициализации.
		void MultiMethod(wisdom* other, ofstream& ofst);	// Диспетчер
		void MM_Aphorism(ofstream& ofst);					// Функция вывода себя с афоризмом
		void MM_Proverb(ofstream& ofst);					// Функция вывода себя с пословицей
		void MM_Riddle(ofstream& ofst);						// Функция вывода себя с загадкой
	};
}
#endif
