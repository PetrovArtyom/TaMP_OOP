#ifndef __container_atd__
#define __container_atd__

#include "wisdom_atd.h"

namespace simple_wisdom 
{
	// Простейший контейнер на основе одномерного массива
	class container 
	{
		// Максимальная длина
		enum { max_len = 100 };

		// Массив объектов типа "мудрость"
		wisdom* cont[max_len];

	public:
		// Текущая длина
		int len;

		// Объявление методов контейнера
		int In(ifstream& ifst); 
		void Out(ofstream& ofst); 
		void Out_proverb(ofstream& ofst); 
		container();
		void Clear();
		void Sort();  
		~container() 
		{
			Clear(); 
		}
	};
}
#endif
