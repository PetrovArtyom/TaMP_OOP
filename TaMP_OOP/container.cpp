#include "container_atd.h"
#include <iostream>
namespace simple_wisdom 
{
	// Инициализация контейнера
	container::container() : len(0) { }
	// Очистка контейнера от элементов
	void container::Clear() {
		for (int i = 0; i < len; i++) {
			delete cont[i];
		}
		len = 0;
	}

	// Ввод содержимого контейнера
	void container::In(ifstream& ifst)
	{
		while (!ifst.eof())
		{
			if (len < max_len)                         // если массив не переполнен
			{
				if ((cont[len] = wisdom::In(ifst)) != 0)
				{
					positions[len] = len;
					len++;
				}
			}
			else
			{
				cout << "Массив переполнен. Считано " << max_len << " элементов" << endl;
				ifst.close();
			}
		}
	}

	// Вывод содержимого контейнера
	void container::Out(ofstream& ofst)
	{
		ofst << "Количество элементов в контейнере: " << len << endl << endl;
		cout << "Количество элементов в контейнере: " << len << endl << endl;
		for (int i = 0; i < len; i++)
		{
			ofst << i + 1 << ": ";
			cont[positions[i]]->Out(ofst);
			//cont[i]->Out(ofst);
			ofst << "Знаков препинания: " << cont[positions[i]]->marks_number() << endl << endl;
		}
	}

	//  Сортировка контейнера
	void container::Sort()
	{
		for (int i = 0; i < len; i++)
		{
			mark_nums[i] = cont[i]->marks_number();
		}

		bool was_change = false;

		do
		{
			was_change = false;

			for (int i = 0; i < len - 1; i++)
			{
				if (mark_nums[i] > mark_nums[i + 1])
				{
					int tmp = mark_nums[i];
					mark_nums[i] = mark_nums[i + 1];
					mark_nums[i + 1] = tmp;

					tmp = positions[i];
					positions[i] = positions[i + 1];
					positions[i + 1] = tmp;

					was_change = true;
				}
			}

		} while (was_change);

	}
}
