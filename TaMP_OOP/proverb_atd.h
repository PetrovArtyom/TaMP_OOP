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
		int marks_number();  // подсчёт знаков препинания
		proverb() {} // создание без инициализации.
	};
}
#endif
