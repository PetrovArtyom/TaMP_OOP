#ifndef __proverb_atd__
#define __proverb_atd__
// ��������� �������� ������ shape
#include "wisdom_atd.h"
namespace simple_wisdom
{
	// ���������
	class proverb : public wisdom
	{
		char country[50];
	public:
		// �������������� ��������� ������
		void InData(ifstream& ifst); // ����
		void Out(ofstream& ofst); // �����
		int marks_number();  // ������� ������ ����������
		proverb() {} // �������� ��� �������������.
	};
}
#endif
