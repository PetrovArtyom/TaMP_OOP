// TaMP_OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <ctime>
#include <iostream>
#include <fstream>
#include "container_atd.h"

using namespace std;
int main(int argc, char* argv[])
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");

	if (argc != 3)
	{
		cout << "incorrect command line! " "Waited: command in_file out_file" << endl;
		system("pause");
		return 0;
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	cout << "Начало выполнения ООП" << endl;
	simple_wisdom::container c;

	if (int check = c.In(ifst) == 1)
	{
		return 0;
	}
	ofst << "Контейнер заполнен" << endl << endl;
	cout << "Контейнер заполнен" << endl << endl;
	ofst << "Стандартный вывод" << endl << endl;
	cout << "Стандартный вывод" << endl << endl;
	c.Out(ofst);
	c.Sort();
	ofst << "Контейнер отсортирован" << endl << endl;
	cout << "Контейнер отсортирован" << endl << endl;
	ofst << "Отсортированный вывод" << endl << endl;
	cout << "Отсортированный вывод" << endl << endl;
	c.Out(ofst);
	ofst << "Фильтрованный вывод" << endl << endl;
	cout << "Фильтрованный вывод" << endl << endl;
	c.Out_proverb(ofst);
	c.Clear();
	ofst << "Контейнер пуст" << endl << endl;
	cout << "Контейнер пуст" << endl << endl;
	c.Out(ofst);
	cout << "Конец выполнения программы" << endl;
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
