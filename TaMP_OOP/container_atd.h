#ifndef __container_atd__
#define __container_atd__
#include "wisdom_atd.h"
namespace simple_wisdom 
{
	// Простейший контейнер на основе одномерного массива
	class container 
	{
		enum { max_len = 100 }; // максимальная длина
		int len; // текущая длина
		wisdom* cont[max_len];

	public:
		void In(ifstream& ifst); // ввод
		void Out(ofstream& ofst); // вывод
		void Out_proverb(ofstream& ofst);       // фильтрованный вывод
		container(); // инициализация контейнера
		void Clear(); // очистка контейнера
		void Sort();  // сортировка контейнера
		~container() { Clear(); } // утилизация контейнера
	};
}
#endif
