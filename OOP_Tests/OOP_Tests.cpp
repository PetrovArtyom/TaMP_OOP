#include "pch.h"
#include "CppUnitTest.h"
#include "../TaMP_OOP/aphorism_atd.h"
#include "../TaMP_OOP/wisdom_atd.h"
#include "../TaMP_OOP/proverb_atd.h"
#include "../TaMP_OOP/riddle_atd.h"
#include "../TaMP_OOP/container_atd.h"
#include <iostream>
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OOPTests
{
	TEST_CLASS(OOPTests)
	{
	public:

		TEST_METHOD(Test_Input_Container)
		{
			std::ifstream ifstr1("cont_in_1.txt");						// Читаем 0 элементов
			std::ifstream ifstr2("cont_in_2.txt");						// Читаем норму - 3 элемента
			std::ifstream ifstr3("cont_in_3.txt");						// Читаем переполнение - 105 элементов

			simple_wisdom::container c1;
			simple_wisdom::container c2;
			simple_wisdom::container c3;

			c1.In(ifstr1);
			c2.In(ifstr2);
			c3.In(ifstr3);

			Assert::AreEqual(0, c1.len, L"Неверно считан пустой файл");
			Assert::AreEqual(3, c2.len, L"Неверно считан нормального размера файл");
			Assert::AreEqual(100, c3.len, L"Неверно считан переполненный файл");
		}

		TEST_METHOD(Test_Clear_Container)
		{
			std::ifstream ifstr1("cont_in_1.txt");						// Читаем 0 элементов
			std::ifstream ifstr2("cont_in_2.txt");						// Читаем норму - 3 элемента
			std::ofstream ofstr1("cont_clear_1.txt");
			std::ofstream ofstr2("cont_clear_2.txt");

			simple_wisdom::container c1;
			simple_wisdom::container c2;

			c1.In(ifstr1);
			c2.In(ifstr2);
			
			c1.Clear();
			c2.Clear();

			c1.Out(ofstr1);
			c2.Out(ofstr2);

			string text_sample;
			string text_just;

			// Проверка первой ситуации (вывод пустого контейнера)
			std::ifstream ifst_check1("cont_clear_1.txt");
			std::ifstream ifst_check_sample1("cont_clear_sample.txt");

			while (!(ifst_check1.eof() || ifst_check_sample1.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check1, text_just);
				getline(ifst_check_sample1, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Ситуация1. Не совпадает строка");			// Сравниваем построчно файлы
			}

			// Проверка второй ситуации (вывод нормального контейнера)
			std::ifstream ifst_check2("cont_clear_2.txt");
			std::ifstream ifst_check_sample2("cont_clear_sample.txt");

			while (!(ifst_check2.eof() || ifst_check_sample2.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check2, text_just);
				getline(ifst_check_sample2, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Ситуация2. Не совпадает строка");			// Сравниваем построчно файлы
			}
		}

		TEST_METHOD(Test_Output_Container)
		{
			std::ifstream ifstr1("cont_in_1.txt");						// Читаем 0 элементов
			std::ifstream ifstr2("cont_in_2.txt");						// Читаем норму - 3 элемента
			std::ifstream ifstr3("cont_in_3.txt");						// Читаем переполнение - 105 элементов

			std::ofstream ofstr1("cont_out_1.txt");						// Записываем первый файл (должен быть 0)
			std::ofstream ofstr2("cont_out_2.txt");						// Записываем второй файл (должен быть 3)
			std::ofstream ofstr3("cont_out_3.txt");						// Записываем третий файл (должен быть 100)

			// Создаём объекты контейнера
			simple_wisdom::container c1;
			simple_wisdom::container c2;
			simple_wisdom::container c3;

			// Заполняем контейнеры
			c1.In(ifstr1);
			c2.In(ifstr2);
			c3.In(ifstr3);

			// Выводим данные с контейнеров
			c1.Out(ofstr1);
			c2.Out(ofstr2);
			c3.Out(ofstr3);

			// Проверка первой ситуации (вывод пустого контейнера)
			std::ifstream ifst_check1("cont_out_1.txt");
			std::ifstream ifst_check_sample1("cont_out_1_sample.txt");

			string text_sample;
			string text_just;

			while (!(ifst_check1.eof() || ifst_check_sample1.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check1, text_just);
				getline(ifst_check_sample1, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Ситуация1. Не совпадает строка");			// Сравниваем построчно файлы
			}

			// Проверка второй ситуации (вывод нормального контейнера)
			std::ifstream ifst_check2("cont_out_2.txt");
			std::ifstream ifst_check_sample2("cont_out_2_sample.txt");

			while (!(ifst_check2.eof() || ifst_check_sample2.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check2, text_just);
				getline(ifst_check_sample2, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Ситуация2. Не совпадает строка");			// Сравниваем построчно файлы
			}

			// Проверка третьей ситуации (вывод полного контейнера)
			std::ifstream ifst_check3("cont_out_3.txt");
			std::ifstream ifst_check_sample3("cont_out_3_sample.txt");
			
			while (!(ifst_check3.eof() || ifst_check_sample3.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check3, text_just);
				getline(ifst_check_sample3, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Ситуация3. Не совпадает строка");			// Сравниваем построчно файлы
			}	
		}

		TEST_METHOD(Test_Filter_Output_Container)
		{
			std::ifstream ifstr1("cont_filter_in_1.txt");							// Различные мудрости
			std::ifstream ifstr2("cont_filter_in_2.txt");							// Только те, которые вывести
			std::ifstream ifstr3("cont_filter_in_3.txt");							// Все, кроме выводимых

			std::ofstream ofstr1("cont_filter_out_1.txt");		
			std::ofstream ofstr2("cont_filter_out_2.txt");
			std::ofstream ofstr3("cont_filter_out_3.txt");

			// Создаём объекты контейнера
			simple_wisdom::container c1;
			simple_wisdom::container c2;
			simple_wisdom::container c3;

			// Заполняем контейнеры
			c1.In(ifstr1);
			c2.In(ifstr2);
			c3.In(ifstr3);

			// Выводим данные с контейнеров
			c1.Out_proverb(ofstr1);
			c2.Out_proverb(ofstr2);
			c3.Out_proverb(ofstr3);

			// Проверка первой ситуации 
			std::ifstream ifst_check1("cont_filter_out_1.txt");
			std::ifstream ifst_check_sample1("cont_filter_out_sample_1.txt");

			string text_sample;
			string text_just;

			while (!(ifst_check1.eof() || ifst_check_sample1.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check1, text_just);
				getline(ifst_check_sample1, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Ситуация1. Не совпадает строка");			// Сравниваем построчно файлы
			}

			// Проверка второй ситуации 
			std::ifstream ifst_check2("cont_filter_out_2.txt");
			std::ifstream ifst_check_sample2("cont_filter_out_sample_2.txt");

			while (!(ifst_check2.eof() || ifst_check_sample2.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check2, text_just);
				getline(ifst_check_sample2, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Ситуация2. Не совпадает строка");			// Сравниваем построчно файлы
			}

			// Проверка третьей ситуации 
			std::ifstream ifst_check3("cont_filter_out_3.txt");
			std::ifstream ifst_check_sample3("cont_filter_out_sample_3.txt");

			while (!(ifst_check3.eof() || ifst_check_sample3.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check3, text_just);
				getline(ifst_check_sample3, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Ситуация2. Не совпадает строка");			// Сравниваем построчно файлы
			}
		}

		TEST_METHOD(Test_Sort_Container)
		{
			std::ifstream ifstr1("cont_sort_in_1.txt");							// Правильно отсортированный массив
			std::ifstream ifstr2("cont_sort_in_2.txt");							// Не отсортированный массив
			std::ifstream ifstr3("cont_sort_in_3.txt");							// Обратно отсортированный массив

			std::ofstream ofstr1("cont_sort_out_1.txt");						
			std::ofstream ofstr2("cont_sort_out_2.txt");						
			std::ofstream ofstr3("cont_sort_out_3.txt");						

			// Создаём объекты контейнера
			simple_wisdom::container c1;
			simple_wisdom::container c2;
			simple_wisdom::container c3;

			// Заполняем контейнеры
			c1.In(ifstr1);
			c2.In(ifstr2);
			c3.In(ifstr3);

			// Сортируем контейнеры
			c1.Sort();
			c2.Sort();
			c3.Sort();

			// Выводим данные с контейнеров
			c1.Out(ofstr1);
			c2.Out(ofstr2);
			c3.Out(ofstr3);

			// Проверка первой ситуации 
			std::ifstream ifst_check1("cont_sort_out_1.txt");
			std::ifstream ifst_check_sample1("cont_sort_sample_1.txt");

			string text_sample;
			string text_just;

			while (!(ifst_check1.eof() || ifst_check_sample1.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check1, text_just);
				getline(ifst_check_sample1, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Ситуация1. Не совпадает строка");			// Сравниваем построчно файлы
			}

			// Проверка второй ситуации 
			std::ifstream ifst_check2("cont_sort_out_2.txt");
			std::ifstream ifst_check_sample2("cont_sort_sample_2.txt");

			while (!(ifst_check2.eof() || ifst_check_sample2.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check2, text_just);
				getline(ifst_check_sample2, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Ситуация2. Не совпадает строка");			// Сравниваем построчно файлы
			}

			// Проверка третьей ситуации 
			std::ifstream ifst_check3("cont_sort_out_3.txt");
			std::ifstream ifst_check_sample3("cont_sort_sample_3.txt");

			while (!(ifst_check3.eof() || ifst_check_sample3.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check3, text_just);
				getline(ifst_check_sample3, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Ситуация3. Не совпадает строка");			// Сравниваем построчно файлы
			}
		}

		TEST_METHOD(Test_mark_number)
		{
			std::ifstream ifstr("cont_in.txt");						// Читаем норму - 3 элемента

			simple_wisdom::wisdom* w1;
			simple_wisdom::wisdom* w2;
			simple_wisdom::wisdom* w3;

			w1 = simple_wisdom::wisdom::In(ifstr);
			w2 = simple_wisdom::wisdom::In(ifstr);
			w3 = simple_wisdom::wisdom::In(ifstr);

			Assert::AreEqual(0, w1->marks_number(), L"Неправильное количество запятых у 1-го элемента");
			Assert::AreEqual(2, w2->marks_number(), L"Неправильное количество запятых у 2-го элемента");
			Assert::AreEqual(5, w3->marks_number(), L"Неправильное количество запятых у 3-го элемента");
		}

		TEST_METHOD(Test_Parent_Class_Input)
		{
			std::ifstream ifstr("par_class_in.txt");

			simple_wisdom::wisdom* w1;
			simple_wisdom::wisdom* w2;
			simple_wisdom::wisdom* w3;

			w1 = simple_wisdom::wisdom::In(ifstr);
			w2 = simple_wisdom::wisdom::In(ifstr);
			w3 = simple_wisdom::wisdom::In(ifstr);

			Assert::AreEqual("Семь раз отмерь и иди спать.", w1->content, L"Неправильное количество запятых у 1-го элемента");
			Assert::AreEqual("Висит груша - нельзя скушать?", w2->content, L"Неправильное количество запятых у 2-го элемента");
			Assert::AreEqual("Безумно можно быть первым", w3->content, L"Неправильное количество запятых у 3-го элемента");
		}

		TEST_METHOD(Test_Parent_Class_Output)
		{
			std::ifstream ifstr("par_class_in.txt");
			std::ofstream ofstr("par_class_out.txt");

			simple_wisdom::wisdom* w1;
			simple_wisdom::wisdom* w2;
			simple_wisdom::wisdom* w3;

			w1 = simple_wisdom::wisdom::In(ifstr);
			w2 = simple_wisdom::wisdom::In(ifstr);
			w3 = simple_wisdom::wisdom::In(ifstr);

			w1->Out(ofstr);
			w2->Out(ofstr);
			w3->Out(ofstr);

			// Проверка 
			std::ifstream ifst_check("par_class_out.txt");
			std::ifstream ifst_check_sample("par_class_out_sample.txt");

			string text_sample;
			string text_just;

			while (!(ifst_check.eof() || ifst_check_sample.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check, text_just);
				getline(ifst_check_sample, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Не совпадает строка");					// Сравниваем построчно файлы
			}
		}

		TEST_METHOD(Test_Daughter_Class_Input)
		{
			std::ifstream ifstr("daug_class_in.txt");
			//std::ofstream ifstr("daug_class_out.");

			simple_wisdom::aphorism w1;
			simple_wisdom::proverb w2;
			simple_wisdom::riddle w3;

			w1.InData(ifstr);
			Assert::AreEqual("Волков", w1.author, L"Ошибка в афоризме");

			w2.InData(ifstr);
			Assert::AreEqual("Россия", w2.country, L"Ошибка в пословице");

			w3.InData(ifstr);
			Assert::AreEqual("Замок", w3.answer, L"Ошибка в загадке");
		}

		TEST_METHOD(Test_Daughter_Class_Output)
		{
			std::ifstream ifstr("daug_class_in.txt");
			std::ofstream ofstr("daug_class_out.txt");

			simple_wisdom::aphorism w1;
			simple_wisdom::proverb w2;
			simple_wisdom::riddle w3;

			w1.InData(ifstr);
			w2.InData(ifstr);
			w3.InData(ifstr);
			
			string str1 = "Я запрещаю вам плакать";			
			for (int i = 0; i < str1.length(); i++)
			{
				w1.content[i] = str1[i];
			}

			string str2 = "Семь раз отмерь и иди спать";
			for (int i = 0; i < str2.length(); i++)
			{
				w2.content[i] = str2[i];
			}

			string str3 = "Ни лает, ни кусает - в дом не пускает";
			for (int i = 0; i < str3.length(); i++)
			{
				w3.content[i] = str3[i];
			}

			w1.mark = 4;
			w2.mark = 7;
			w3.mark = 2;

			w1.Out(ofstr);
			w2.Out(ofstr);
			w3.Out(ofstr);

			// Проверка 
			std::ifstream ifst_check("daug_class_out.txt");
			std::ifstream ifst_check_sample("daug_class_out_sample.txt");

			string text_sample;
			string text_just;

			while (!(ifst_check.eof() || ifst_check_sample.eof()))									//Пока не конец одного из файлов
			{
				getline(ifst_check, text_just);
				getline(ifst_check_sample, text_sample);
				Assert::AreEqual(text_sample, text_just, L"Не совпадает строка");					// Сравниваем построчно файлы
			}
		}
	};
}
