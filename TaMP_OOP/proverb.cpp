#include "proverb_atd.h"
using namespace std;
namespace simple_wisdom
{
	// ���� ���������� ��������
	void proverb::InData(ifstream& ifst)
	{
		ifst.getline(country, 50);
	}

	// ����� ���������� ��������
	void proverb::Out(ofstream& ofst)
	{
		ofst << "������: " << country << endl << "���������: ";
		wisdom::Out(ofst);
	}

	void proverb::Out_proverb(ofstream& ofst)
	{
		ofst << "������: " << country << endl << "���������: " << content << endl << "������: " << mark << endl << "������ ����������: " << marks_number() << endl << endl;
	}
}
