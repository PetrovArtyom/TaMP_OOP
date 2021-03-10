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
			if (len < max_len)
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
			ofst << i + 1 << ": ";
			cont[i]->Out(ofst);
		}
	}
}
