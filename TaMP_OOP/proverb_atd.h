#ifndef __proverb_atd__
#define __proverb_atd__

#include "wisdom_atd.h"

namespace simple_wisdom
{
	// Определение дочернего класса - пословица
	class proverb : public wisdom
	{
	public:
		// Строка для хранения страны
		char country[50];

		// Переопределение интерфейса класса

		// Ввод
		int InData(ifstream& ifst);
		
		// Вывод
		void Out(ofstream& ofst);
		
		// Фильтрованный вывод
		void Out_proverb(ofstream& ofst);
		
		// Создание без инициализации
		proverb() 
		{
		
		}
	};
}
#endif
