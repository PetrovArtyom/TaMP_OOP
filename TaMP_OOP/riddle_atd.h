#ifndef __riddle_atd__
#define __riddle_atd__

#include "wisdom_atd.h"

namespace simple_wisdom
{
	// ����������� ��������� ������ - �������
	class riddle : public wisdom
	{
	public:
		// ������ ��� �������� ������
		char answer[50];

		// ��������������� ���������� ������

		// ����
		int In_data(ifstream& ifst);
		
		// �����
		void Out(ofstream& ofst); 
		
		// �������� ��� �������������
		riddle() 
		{
		
		} 
	};
}
#endif