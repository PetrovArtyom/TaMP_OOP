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
		int marks_number();   // ������� ������ ����������
		aphorism() {} // �������� ��� �������������.
	};
}
#endif