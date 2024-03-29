#include "container_atd.h"
#include <iostream>

namespace simple_wisdom 
{
	// ������������� ����������
	container::container() : len(0) 
	{

	}

	// ������� ���������� �� ��������� (������������ ������)
	void container::Clear() 
	{
		for (int i = 0; i < len; i++) 
		{
			delete cont[i];
		}
		len = 0;
	}

	// ���� ����������� ���������� �� ���������� ������
	int container::In(ifstream& ifst)
	{
		// ������ ���� �� ����� �����
		while (!ifst.eof())
		{
			// �������� �� �������������� ������� ��������� 
			if (len < max_len)                         
			{
				// �������� �� �������� ����
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
				cout << "������ ����������. ������� " << max_len << " ���������" << endl;
				ifst.close();
				break;
			}
		}
		return 0;
	}

	// ����� ����������� ���������� � ��������� �����
	void container::Out(ofstream& ofst)
	{
		ofst << "���������� ��������� � ����������: " << len << endl << endl;
		cout << "���������� ��������� � ����������: " << len << endl << endl;
		
		for (int i = 0; i < len; i++)
		{
			cont[i]->Out(ofst);
			ofst << "������ ����������: " << cont[i]->Marks_number() << endl << endl;
		}
	}

	// ������������� ����� ����������� ���������� � ��������� �����
	void container::Out_proverb(ofstream& ofst)
	{
		ofst << "���������� ��������� � ����������: " << len << endl << endl;
		cout << "���������� ��������� � ����������: " << len << endl << endl;

		for (int i = 0; i < len; i++)
		{
			cont[i]->Out_proverb(ofst);
		}
	}

	//  ���������� ����������
	void container::Sort()
	{
		for (int i = 0; i < len - 1; i++)
		{

			for (int j = i + 1; j < len; j++)
			{
				if (cont[i]->Compare(cont[j]))
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
