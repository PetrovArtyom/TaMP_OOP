#ifndef __proverb_atd__
#define __proverb_atd__
// Требеутся описание класса shape
#include "wisdom_atd.h"
namespace simple_wisdom
{
	// пословица
	class proverb : public wisdom
	{
	public:
		char country[50];
		// переопределяем интерфейс класса
		void InData(ifstream& ifst); // ввод
		void Out(ofstream& ofst); // вывод
		void Out_proverb(ofstream& ofst);
		proverb() {} // создание без инициализации.
	};
}
#endif
