#ifndef __proverb_atd__
#define __proverb_atd__

#include "wisdom_atd.h"

namespace simple_wisdom
{
	// ����������� ��������� ������ - ���������
	class proverb : public wisdom
	{
	public:
		// ������ ��� �������� ������
		char country[50];

		// ��������������� ���������� ������

		// ����
		int In_data(ifstream& ifst);
		
		// �����
		void Out(ofstream& ofst);
		
		// ������������� �����
		void Out_proverb(ofstream& ofst);
		
		// �������� ��� �������������
		proverb() 
		{
		
		}
	};
}
#endif
