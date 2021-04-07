#ifndef __riddle_atd__
#define __riddle_atd__
// ��������� �������� ������ wisdom
#include "wisdom_atd.h"
namespace simple_wisdom
{
	// �������
	class riddle : public wisdom
	{
		char answer[50];
	public:
		// �������������� ���������� ������
		void InData(ifstream& ifst); // ����
		void Out(ofstream& ofst); // �����
		riddle() {} // �������� ��� �������������.
		void MultiMethod(wisdom* other, ofstream& ofst);	// ���������
		void MM_Aphorism(ofstream& ofst);					// ������� ������ ���� � ���������
		void MM_Proverb(ofstream& ofst);					// ������� ������ ���� � ����������
		void MM_Riddle(ofstream& ofst);						// ������� ������ ���� � ��������
	};
}
#endif
