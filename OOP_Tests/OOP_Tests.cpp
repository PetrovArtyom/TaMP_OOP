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
			std::ifstream ifstr1("cont_in_1.txt");						// ������ 0 ���������
			std::ifstream ifstr2("cont_in_2.txt");						// ������ ����� - 3 ��������
			std::ifstream ifstr3("cont_in_3.txt");						// ������ ������������ - 105 ���������

			simple_wisdom::container c1;
			simple_wisdom::container c2;
			simple_wisdom::container c3;

			c1.In(ifstr1);
			c2.In(ifstr2);
			c3.In(ifstr3);

			Assert::AreEqual(0, c1.len, L"������� ������ ������ ����");
			Assert::AreEqual(3, c2.len, L"������� ������ ����������� ������� ����");
			Assert::AreEqual(100, c3.len, L"������� ������ ������������� ����");
		}

		TEST_METHOD(Test_Clear_Container)
		{
			std::ifstream ifstr1("cont_in_1.txt");						// ������ 0 ���������
			std::ifstream ifstr2("cont_in_2.txt");						// ������ ����� - 3 ��������
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

			// �������� ������ �������� (����� ������� ����������)
			std::ifstream ifst_check1("cont_clear_1.txt");
			std::ifstream ifst_check_sample1("cont_clear_sample.txt");

			while (!(ifst_check1.eof() || ifst_check_sample1.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check1, text_just);
				getline(ifst_check_sample1, text_sample);
				Assert::AreEqual(text_sample, text_just, L"��������1. �� ��������� ������");			// ���������� ��������� �����
			}

			// �������� ������ �������� (����� ����������� ����������)
			std::ifstream ifst_check2("cont_clear_2.txt");
			std::ifstream ifst_check_sample2("cont_clear_sample.txt");

			while (!(ifst_check2.eof() || ifst_check_sample2.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check2, text_just);
				getline(ifst_check_sample2, text_sample);
				Assert::AreEqual(text_sample, text_just, L"��������2. �� ��������� ������");			// ���������� ��������� �����
			}
		}

		TEST_METHOD(Test_Output_Container)
		{
			std::ifstream ifstr1("cont_in_1.txt");						// ������ 0 ���������
			std::ifstream ifstr2("cont_in_2.txt");						// ������ ����� - 3 ��������
			std::ifstream ifstr3("cont_in_3.txt");						// ������ ������������ - 105 ���������

			std::ofstream ofstr1("cont_out_1.txt");						// ���������� ������ ���� (������ ���� 0)
			std::ofstream ofstr2("cont_out_2.txt");						// ���������� ������ ���� (������ ���� 3)
			std::ofstream ofstr3("cont_out_3.txt");						// ���������� ������ ���� (������ ���� 100)

			// ������ ������� ����������
			simple_wisdom::container c1;
			simple_wisdom::container c2;
			simple_wisdom::container c3;

			// ��������� ����������
			c1.In(ifstr1);
			c2.In(ifstr2);
			c3.In(ifstr3);

			// ������� ������ � �����������
			c1.Out(ofstr1);
			c2.Out(ofstr2);
			c3.Out(ofstr3);

			// �������� ������ �������� (����� ������� ����������)
			std::ifstream ifst_check1("cont_out_1.txt");
			std::ifstream ifst_check_sample1("cont_out_1_sample.txt");

			string text_sample;
			string text_just;

			while (!(ifst_check1.eof() || ifst_check_sample1.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check1, text_just);
				getline(ifst_check_sample1, text_sample);
				Assert::AreEqual(text_sample, text_just, L"��������1. �� ��������� ������");			// ���������� ��������� �����
			}

			// �������� ������ �������� (����� ����������� ����������)
			std::ifstream ifst_check2("cont_out_2.txt");
			std::ifstream ifst_check_sample2("cont_out_2_sample.txt");

			while (!(ifst_check2.eof() || ifst_check_sample2.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check2, text_just);
				getline(ifst_check_sample2, text_sample);
				Assert::AreEqual(text_sample, text_just, L"��������2. �� ��������� ������");			// ���������� ��������� �����
			}

			// �������� ������� �������� (����� ������� ����������)
			std::ifstream ifst_check3("cont_out_3.txt");
			std::ifstream ifst_check_sample3("cont_out_3_sample.txt");
			
			while (!(ifst_check3.eof() || ifst_check_sample3.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check3, text_just);
				getline(ifst_check_sample3, text_sample);
				Assert::AreEqual(text_sample, text_just, L"��������3. �� ��������� ������");			// ���������� ��������� �����
			}	
		}

		TEST_METHOD(Test_Filter_Output_Container)
		{
			std::ifstream ifstr1("cont_filter_in_1.txt");							// ��������� ��������
			std::ifstream ifstr2("cont_filter_in_2.txt");							// ������ ��, ������� �������
			std::ifstream ifstr3("cont_filter_in_3.txt");							// ���, ����� ���������

			std::ofstream ofstr1("cont_filter_out_1.txt");		
			std::ofstream ofstr2("cont_filter_out_2.txt");
			std::ofstream ofstr3("cont_filter_out_3.txt");

			// ������ ������� ����������
			simple_wisdom::container c1;
			simple_wisdom::container c2;
			simple_wisdom::container c3;

			// ��������� ����������
			c1.In(ifstr1);
			c2.In(ifstr2);
			c3.In(ifstr3);

			// ������� ������ � �����������
			c1.Out_proverb(ofstr1);
			c2.Out_proverb(ofstr2);
			c3.Out_proverb(ofstr3);

			// �������� ������ �������� 
			std::ifstream ifst_check1("cont_filter_out_1.txt");
			std::ifstream ifst_check_sample1("cont_filter_out_sample_1.txt");

			string text_sample;
			string text_just;

			while (!(ifst_check1.eof() || ifst_check_sample1.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check1, text_just);
				getline(ifst_check_sample1, text_sample);
				Assert::AreEqual(text_sample, text_just, L"��������1. �� ��������� ������");			// ���������� ��������� �����
			}

			// �������� ������ �������� 
			std::ifstream ifst_check2("cont_filter_out_2.txt");
			std::ifstream ifst_check_sample2("cont_filter_out_sample_2.txt");

			while (!(ifst_check2.eof() || ifst_check_sample2.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check2, text_just);
				getline(ifst_check_sample2, text_sample);
				Assert::AreEqual(text_sample, text_just, L"��������2. �� ��������� ������");			// ���������� ��������� �����
			}

			// �������� ������� �������� 
			std::ifstream ifst_check3("cont_filter_out_3.txt");
			std::ifstream ifst_check_sample3("cont_filter_out_sample_3.txt");

			while (!(ifst_check3.eof() || ifst_check_sample3.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check3, text_just);
				getline(ifst_check_sample3, text_sample);
				Assert::AreEqual(text_sample, text_just, L"��������2. �� ��������� ������");			// ���������� ��������� �����
			}
		}

		TEST_METHOD(Test_Sort_Container)
		{
			std::ifstream ifstr1("cont_sort_in_1.txt");							// ��������� ��������������� ������
			std::ifstream ifstr2("cont_sort_in_2.txt");							// �� ��������������� ������
			std::ifstream ifstr3("cont_sort_in_3.txt");							// ������� ��������������� ������

			std::ofstream ofstr1("cont_sort_out_1.txt");						
			std::ofstream ofstr2("cont_sort_out_2.txt");						
			std::ofstream ofstr3("cont_sort_out_3.txt");						

			// ������ ������� ����������
			simple_wisdom::container c1;
			simple_wisdom::container c2;
			simple_wisdom::container c3;

			// ��������� ����������
			c1.In(ifstr1);
			c2.In(ifstr2);
			c3.In(ifstr3);

			// ��������� ����������
			c1.Sort();
			c2.Sort();
			c3.Sort();

			// ������� ������ � �����������
			c1.Out(ofstr1);
			c2.Out(ofstr2);
			c3.Out(ofstr3);

			// �������� ������ �������� 
			std::ifstream ifst_check1("cont_sort_out_1.txt");
			std::ifstream ifst_check_sample1("cont_sort_sample_1.txt");

			string text_sample;
			string text_just;

			while (!(ifst_check1.eof() || ifst_check_sample1.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check1, text_just);
				getline(ifst_check_sample1, text_sample);
				Assert::AreEqual(text_sample, text_just, L"��������1. �� ��������� ������");			// ���������� ��������� �����
			}

			// �������� ������ �������� 
			std::ifstream ifst_check2("cont_sort_out_2.txt");
			std::ifstream ifst_check_sample2("cont_sort_sample_2.txt");

			while (!(ifst_check2.eof() || ifst_check_sample2.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check2, text_just);
				getline(ifst_check_sample2, text_sample);
				Assert::AreEqual(text_sample, text_just, L"��������2. �� ��������� ������");			// ���������� ��������� �����
			}

			// �������� ������� �������� 
			std::ifstream ifst_check3("cont_sort_out_3.txt");
			std::ifstream ifst_check_sample3("cont_sort_sample_3.txt");

			while (!(ifst_check3.eof() || ifst_check_sample3.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check3, text_just);
				getline(ifst_check_sample3, text_sample);
				Assert::AreEqual(text_sample, text_just, L"��������3. �� ��������� ������");			// ���������� ��������� �����
			}
		}

		TEST_METHOD(Test_mark_number)
		{
			std::ifstream ifstr("cont_in.txt");						// ������ ����� - 3 ��������

			simple_wisdom::wisdom* w1;
			simple_wisdom::wisdom* w2;
			simple_wisdom::wisdom* w3;

			w1 = simple_wisdom::wisdom::In(ifstr);
			w2 = simple_wisdom::wisdom::In(ifstr);
			w3 = simple_wisdom::wisdom::In(ifstr);

			Assert::AreEqual(0, w1->marks_number(), L"������������ ���������� ������� � 1-�� ��������");
			Assert::AreEqual(2, w2->marks_number(), L"������������ ���������� ������� � 2-�� ��������");
			Assert::AreEqual(5, w3->marks_number(), L"������������ ���������� ������� � 3-�� ��������");
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

			Assert::AreEqual("���� ��� ������ � ��� �����.", w1->content, L"������������ ���������� ������� � 1-�� ��������");
			Assert::AreEqual("����� ����� - ������ �������?", w2->content, L"������������ ���������� ������� � 2-�� ��������");
			Assert::AreEqual("������� ����� ���� ������", w3->content, L"������������ ���������� ������� � 3-�� ��������");
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

			// �������� 
			std::ifstream ifst_check("par_class_out.txt");
			std::ifstream ifst_check_sample("par_class_out_sample.txt");

			string text_sample;
			string text_just;

			while (!(ifst_check.eof() || ifst_check_sample.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check, text_just);
				getline(ifst_check_sample, text_sample);
				Assert::AreEqual(text_sample, text_just, L"�� ��������� ������");					// ���������� ��������� �����
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
			Assert::AreEqual("������", w1.author, L"������ � ��������");

			w2.InData(ifstr);
			Assert::AreEqual("������", w2.country, L"������ � ���������");

			w3.InData(ifstr);
			Assert::AreEqual("�����", w3.answer, L"������ � �������");
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
			
			string str1 = "� �������� ��� �������";			
			for (int i = 0; i < str1.length(); i++)
			{
				w1.content[i] = str1[i];
			}

			string str2 = "���� ��� ������ � ��� �����";
			for (int i = 0; i < str2.length(); i++)
			{
				w2.content[i] = str2[i];
			}

			string str3 = "�� ����, �� ������ - � ��� �� �������";
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

			// �������� 
			std::ifstream ifst_check("daug_class_out.txt");
			std::ifstream ifst_check_sample("daug_class_out_sample.txt");

			string text_sample;
			string text_just;

			while (!(ifst_check.eof() || ifst_check_sample.eof()))									//���� �� ����� ������ �� ������
			{
				getline(ifst_check, text_just);
				getline(ifst_check_sample, text_sample);
				Assert::AreEqual(text_sample, text_just, L"�� ��������� ������");					// ���������� ��������� �����
			}
		}
	};
}
