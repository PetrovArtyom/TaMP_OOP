#include "aphorism_atd.h"
using namespace std;
namespace simple_wisdom
{
	//���� ���������� ��������
	void aphorism::InData(ifstream& ifst)
	{
		ifst.getline(author, 50);
	}

	//����� ���������� ��������
	void aphorism::Out(ofstream& ofst)
	{
		ofst << "�����: " << author << endl << "�������: ";
		wisdom::Out(ofst);
	}
}