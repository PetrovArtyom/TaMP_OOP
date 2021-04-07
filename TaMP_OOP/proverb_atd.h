#ifndef __proverb_atd__
#define __proverb_atd__
// Требеутся описание класса shape
#include "wisdom_atd.h"
namespace simple_wisdom
{
	// пословица
	class proverb : public wisdom
	{
		char country[50];
	public:
		// переопределяем интерфейс класса
		void InData(ifstream& ifst); // ввод
		void Out(ofstream& ofst); // вывод
		proverb() {} // создание без инициализации
		void MultiMethod(wisdom* other, ofstream& ofst);	// Диспетчер
		void MM_Aphorism(ofstream& ofst);					// Функция вывода себя с афоризмом
		void MM_Proverb(ofstream& ofst) ;					// Функция вывода себя с пословицей
	};
}
#endif
