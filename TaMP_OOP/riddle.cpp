#include "riddle_atd.h"
using namespace std;
namespace simple_wisdom
{
	//���� ���������� �������
	void riddle::InData(ifstream& ifst)
	{
		ifst.getline(answer, 50);
	}

	// ����� ���������� �������
	void riddle::Out(ofstream& ofst)
	{
		ofst << "�����: " << answer << endl << "�������: ";
		wisdom::Out(ofst);
	}
}