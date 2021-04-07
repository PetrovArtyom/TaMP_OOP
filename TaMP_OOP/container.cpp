#include "container_atd.h"
#include <iostream>

namespace simple_wisdom 
{
	// Инициализация контейнера
	container::container() : len(0) 
	{

	}

	// Очистка контейнера от элементов (освобождение памяти)
	void container::Clear() 
	{
		for (int i = 0; i < len; i++) 
		{
			delete cont[i];
		}
		len = 0;
	}

	// Ввод содержимого контейнера из указанного потока
	int container::In(ifstream& ifst)
	{
		// Чтение пока не конец файла
		while (!ifst.eof())
		{
			// Проверка на непереполнение массива элементов 
			if (len < max_len)                         
			{
				// Проверка на успешный ввод
				if ((cont[len] = wisdom::In(ifst)) != 0)
				{
					len++;
				}
				else
				{
					return 1;
				}
			}
			else
			{
				cout << "Массив переполнен. Считано " << max_len << " элементов" << endl;
				ifst.close();
				break;
			}
		}
		return 0;
	}

	// Вывод содержимого контейнера в указанынй поток
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

	// Фильтрованный вывод содержимого контейнера в указанынй поток
	void container::Out_proverb(ofstream& ofst)
	{
		ofst << "Количество элементов в контейнере: " << len << endl << endl;
		cout << "Количество элементов в контейнере: " << len << endl << endl;

		for (int i = 0; i < len; i++)
		{
			cont[i]->Out_proverb(ofst);
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
}
