#ifndef __aphorism_atd__
#define __aphorism_atd__
// ��������� �������� ������ shape
#include "wisdom_atd.h"
namespace simple_wisdom
{
	// �������
	class aphorism : public wisdom
	{
		char author[50];
	public:
		// �������������� ��������� ������
		void InData(ifstream& ifst); // ����
		void Out(ofstream& ofst); // �����
		aphorism() {} // �������� ��� �������������.
		void MultiMethod(wisdom* other, ofstream& ofst);	// ���������
		void MM_Aphorism(ofstream& ofst);					// ������� ������ ���� � ���������
		void MM_Proverb(ofstream& ofst);					// ������� ������ ���� � ����������
		void MM_Riddle(ofstream& ofst);						// ������� ������ ���� � ��������
	};
}
#endif