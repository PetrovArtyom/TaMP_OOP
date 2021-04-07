#include "proverb_atd.h"
using namespace std;
namespace simple_wisdom
{
	// ���� ���������� ��������
	void proverb::InData(ifstream& ifst)
	{
		ifst.getline(content, 200);
		ifst.getline(country, 50);
	}

	// ����� ���������� ��������
	void proverb::Out(ofstream& ofst)
	{
		ofst << "���������: " << content << endl << "������: " << country << endl;
	}

	void proverb::MultiMethod(wisdom* other, ofstream& ofst)
	{
		other->MM_Proverb(ofst);
	}

	void proverb::MM_Aphorism(ofstream& ofst)
	{
		ofst << "������� � ���������" << endl;
	}

	void proverb::MM_Proverb(ofstream& ofst)
	{
		ofst << "��������� � ���������" << endl;
	}
}
