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
			cont[i]->Out(ofst);
			ofst << "Знаков препинания: " << cont[i]->marks_number() << endl << endl;
		}
	}

	//  Сортировка контейнера
	void container::Sort()
	{
		for (int i = 0; i < len - 1; i++)
		{

			for (int j = i + 1; j < len; j++)
			{
				if (cont[i]->compare(cont[j]))
				{
					wisdom* tmp = cont[i];
					cont[i] = cont[j];
					cont[j] = tmp;
					tmp = NULL;
				}
			}
		}
	}

	// Фильтрованный вывод содержимого контейнера
	void container::Out_proverb(ofstream& ofst)
	{
		ofst << "Количество элементов в контейнере: " << len << endl << endl;
		cout << "Количество элементов в контейнере: " << len << endl << endl;
		for (int i = 0; i < len; i++)
		{
			cont[i]->Out_proverb(ofst);
		}
	}
}
