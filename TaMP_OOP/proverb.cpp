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
		ofst << "���������!!!: " << content << endl << "������: " << country << endl;
	}
}
