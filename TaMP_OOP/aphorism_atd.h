#ifndef __aphorism_atd__
#define __aphorism_atd__

#include "wisdom_atd.h"

namespace simple_wisdom
{
	// Определение дочернего класса - афоризм
	class aphorism : public wisdom
	{
	public:
		// Строка для хранения автора
		char author[50];

		// Переопределение интерфейса класса

		// Ввод
		int In_data(ifstream& ifst);

		// Вывод
		void Out(ofstream& ofst);
		
		// Создание без инициализации
		aphorism() 
		{

		}
	};
}
#endif