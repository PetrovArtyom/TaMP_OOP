#include "wisdom_atd.h"
// Необходима подключить информацию обо всех имеющихся
// геометрических фигурах
#include "proverb_atd.h"
#include "aphorism_atd.h"
using namespace std;
namespace simple_wisdom
{
	// Ввод параметров обобщенной фигуры
	wisdom* wisdom::In(ifstream& ifst)
	{
		wisdom* wd;
		int k;
		ifst >> k;
		char tmp;
		ifst.get(tmp);
		switch (k)
		{
		case 1:
			wd = new proverb;
			break;
		case 2:
			wd = new aphorism;
			break;
		default:
			return 0;
		}
		wd->InData(ifst);
		return wd;
	}
	/*
	// Перегрузка оператора присваивания
	wisdom& operator= (const wisdom& wisd)
	{
		content = wisd.content;

		// Возвращаем текущий объект, чтобы иметь возможность связать в цепочку выполнение нескольких операций присваивания
		return *this;
	}*/	
}