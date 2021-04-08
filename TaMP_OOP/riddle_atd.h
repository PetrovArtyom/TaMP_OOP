#ifndef __riddle_atd__
#define __riddle_atd__

#include "wisdom_atd.h"

namespace simple_wisdom
{
	// Определение дочернего класса - загадка
	class riddle : public wisdom
	{
	public:
		// Строка для хранения ответа
		char answer[50];

		// Переопределение интерфейса класса

		// Ввод
		int In_data(ifstream& ifst);
		
		// Вывод
		void Out(ofstream& ofst); 
		
		// Создание без инициализации
		riddle() 
		{
		
		} 
	};
}
#endif