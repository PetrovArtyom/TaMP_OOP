#ifndef __riddle_atd__
#define __riddle_atd__
// ��������� �������� ������ wisdom
#include "wisdom_atd.h"
namespace simple_wisdom
{
	// �������
	class riddle : public wisdom
	{
	public:
		char answer[50];
		// �������������� ��������� ������
		int InData(ifstream& ifst); // ����
		void Out(ofstream& ofst); // �����
		riddle() {} // �������� ��� �������������.
	};
}
#endif