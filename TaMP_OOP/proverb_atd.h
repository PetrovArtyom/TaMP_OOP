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
		proverb() {} // �������� ��� �������������
		void MultiMethod(wisdom* other, ofstream& ofst);	// ���������
		void MM_Aphorism(ofstream& ofst);					// ������� ������ ���� � ���������
		void MM_Proverb(ofstream& ofst) ;					// ������� ������ ���� � ����������
	};
}
#endif
