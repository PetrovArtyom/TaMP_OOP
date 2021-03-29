#include "aphorism_atd.h"
#include <iostream>

using namespace std;
namespace simple_wisdom
{
	//���� ���������� �������� �� ������
	int aphorism::InData(ifstream& ifst)
	{
		// ������ ������
		ifst.getline(author, 50);

		// �������� ������ �� ���������
		if (author[0] == '\0')
		{
			cout << endl << "Error! Field author is empty. Please check input file." << endl;
			return 1;
		}
		return 0;
	}

	//����� ���������� ��������
	void aphorism::Out(ofstream& ofst)
	{
		ofst << "�����: " << author << endl << "�������: ";
		wisdom::Out(ofst);
	}
}