#include "container_atd.h"
#include <iostream>
namespace simple_wisdom 
{
	// ������������� ����������
	container::container() : len(0) { }
	// ������� ���������� �� ���������
	void container::Clear() {
		for (int i = 0; i < len; i++) {
			delete cont[i];
		}
		len = 0;
	}

	// ���� ����������� ����������
	void container::In(ifstream& ifst)
	{
		while (!ifst.eof())
		{
			if (len < max_len)                         // ���� ������ �� ����������
			{
				if ((cont[len] = wisdom::In(ifst)) != 0)
				{
					len++;
				}
			}
			else
			{
				cout << "������ ����������. ������� " << max_len << " ���������" << endl;
				ifst.close();
			}
		}
	}

	// ����� ����������� ����������
	void container::Out(ofstream& ofst)
	{
		ofst << "���������� ��������� � ����������: " << len << endl << endl;
		cout << "���������� ��������� � ����������: " << len << endl << endl;
		for (int i = 0; i < len; i++)
		{
			cont[i]->Out(ofst);
			ofst << "������ ����������: " << cont[i]->marks_number() << endl << endl;
		}
	}

	//  ���������� ����������
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

	// ������������� ����� ����������� ����������
	void container::Out_proverb(ofstream& ofst)
	{
		ofst << "���������� ��������� � ����������: " << len << endl << endl;
		cout << "���������� ��������� � ����������: " << len << endl << endl;
		for (int i = 0; i < len; i++)
		{
			cont[i]->Out_proverb(ofst);
		}
	}
}
