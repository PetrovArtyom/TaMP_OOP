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
					positions[len] = len;
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
			cont[positions[i]]->Out(ofst);
			//cont[i]->Out(ofst);
			ofst << "������ ����������: " << cont[positions[i]]->marks_number() << endl << endl;
		}
	}

	//  ���������� ����������
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
