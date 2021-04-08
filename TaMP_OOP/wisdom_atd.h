#ifndef __wisdom_atd__
#define __wisdom_atd__

#include <fstream>

using namespace std;
namespace simple_wisdom
{
	// Определение родительского класса - мудрость
	class wisdom
	{
	public:
		// Строка для хранения содержания мудрости
		char content[200];

		// Переменная для хранения субъективной оценки
		int mark = 0;

		// Объявление методов класса
		static wisdom* In(ifstream& ifst);
		virtual int In_data(ifstream& ifst) = 0; 
		virtual void Out(ofstream& ofst); 
		virtual void Out_proverb(ofstream& ofst);
		bool Compare(wisdom* a);
		int Marks_number();   
	};
}
#endif
