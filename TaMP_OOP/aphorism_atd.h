#ifndef __aphorism_atd__
#define __aphorism_atd__

#include "wisdom_atd.h"

namespace simple_wisdom
{
	// ����������� ��������� ������ - �������
	class aphorism : public wisdom
	{
	public:
		// ������ ��� �������� ������
		char author[50];

		// ��������������� ���������� ������

		// ����
		int In_data(ifstream& ifst);

		// �����
		void Out(ofstream& ofst);
		
		// �������� ��� �������������
		aphorism() 
		{

		}
	};
}
#endif