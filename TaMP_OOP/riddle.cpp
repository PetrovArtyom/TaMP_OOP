#include "riddle_atd.h"
using namespace std;
namespace simple_wisdom
{
	//���� ���������� �������
	void riddle::InData(ifstream& ifst)
	{
		ifst.getline(content, 200);
		ifst.getline(answer, 50);
	}

	//����� ���������� �������
	void riddle::Out(ofstream& ofst)
	{
		ofst << "�������: " << content << endl << "�����: " << answer << endl;
	}

	void riddle::MultiMethod(wisdom* other, ofstream& ofst)
	{
		other->MM_Riddle(ofst);
	}

	void riddle::MM_Proverb(ofstream& ofst)
	{
		ofst << "��������� � �������" << endl;
	}

	void riddle::MM_Aphorism(ofstream& ofst)
	{
		ofst << "������� � �������" << endl;
	}

	void riddle::MM_Riddle(ofstream& ofst)
	{
		ofst << "������� � �������" << endl;
	}
}