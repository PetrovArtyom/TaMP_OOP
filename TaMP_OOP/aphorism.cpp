#include "aphorism_atd.h"
using namespace std;
namespace simple_wisdom
{
	//���� ���������� ��������
	void aphorism::InData(ifstream& ifst)
	{
		ifst.getline(content, 200);
		ifst.getline(author, 50);
	}

	//����� ���������� ��������
	void aphorism::Out(ofstream& ofst)
	{
		ofst << "�������: " << content << endl << "�����: " << author << endl;
	}

	void aphorism::MultiMethod(wisdom* other, ofstream& ofst)
	{
		other->MM_Aphorism(ofst);
	}

	void aphorism::MM_Proverb(ofstream& ofst)
	{
		ofst << "��������� � �������" << endl;
	}

	void aphorism::MM_Aphorism(ofstream& ofst)
	{
		ofst << "������� � �������" << endl;
	}
}