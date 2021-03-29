#ifndef __aphorism_atd__
#define __aphorism_atd__
// Требуется описание класса shape
#include "wisdom_atd.h"
namespace simple_wisdom
{
	// афоризм
	class aphorism : public wisdom
	{
	public:
		char author[50];
		// переопределяем интерфейс класса
		int InData(ifstream& ifst); // ввод
		void Out(ofstream& ofst); // вывод
		aphorism() {} // создание без инициализации.
	};
}
#endif