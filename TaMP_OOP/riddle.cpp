#include "riddle_atd.h"
#include <iostream>

using namespace std;
namespace simple_wisdom
{
	//���� ���������� ������� �� ������
	int riddle::InData(ifstream& ifst)
	{
		//������ ������
		ifst.getline(answer, 50);
		
		// �������� ������ �� ���������
		if (answer[0] == '\0')
		{
			cout << endl << "Error! Field answer is empty. Please check input file." << endl;
			return 1;
		}
		return 0;
	}

	// ����� ���������� ������� � �����
	void riddle::Out(ofstream& ofst)
	{
		ofst << "�����: " << answer << endl << "�������: ";
		wisdom::Out(ofst);
	}
}