#include "proverb_atd.h"
#include <iostream>

using namespace std;
namespace simple_wisdom
{
	// ���� ���������� ��������� �� ������
	int proverb::InData(ifstream& ifst)
	{
		// ������ ������
		ifst.getline(country, 50);

		// �������� ������ �� ���������
		if (country[0] == '\0')
		{
			cout << endl << "Error! Field country is empty. Please check input file." << endl;
			return 1;
		}
		return 0;
	}

	// ����� ���������� ���������
	void proverb::Out(ofstream& ofst)
	{
		ofst << "������: " << country << endl << "���������: ";
		wisdom::Out(ofst);
	}

	// ������������� ����� ���������
	void proverb::Out_proverb(ofstream& ofst)
	{
		ofst << "������: " << country << endl << "���������: " << content << endl << "������: " << mark << endl << "������ ����������: " << marks_number() << endl << endl;
	}
}
