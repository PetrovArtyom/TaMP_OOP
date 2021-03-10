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
	};
}
#endif