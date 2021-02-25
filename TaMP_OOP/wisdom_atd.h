#ifndef __wisdom_atd__
#define __wisdom_atd__
#include <fstream>
using namespace std;
namespace simple_wisdom
{
	class wisdom
	{
	public:
		char content[200];

		// иденитфикация, порождение и ввод фигуры из потока
		static wisdom* In(ifstream& ifst);
		virtual void InData(ifstream& ifst) = 0; // ввод
		virtual void Out(ofstream& ofst) = 0; // вывод
	};
}
#endif
