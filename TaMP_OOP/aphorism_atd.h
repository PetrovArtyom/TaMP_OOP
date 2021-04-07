#ifndef __aphorism_atd__
#define __aphorism_atd__
// Требуется описание класса shape
#include "wisdom_atd.h"
namespace simple_wisdom
{
	// афоризм
	class aphorism : public wisdom
	{
		char author[50];
	public:
		// переопределяем интерфейс класса
		void InData(ifstream& ifst); // ввод
		void Out(ofstream& ofst); // вывод
		aphorism() {} // создание без инициализации.
		void MultiMethod(wisdom* other, ofstream& ofst);	// Диспетчер
		void MM_Aphorism(ofstream& ofst);					// Функция вывода себя с афоризмом
		void MM_Proverb(ofstream& ofst);					// Функция вывода себя с пословицей
		void MM_Riddle(ofstream& ofst);						// Функция вывода себя с загадкой
	};
}
#endif