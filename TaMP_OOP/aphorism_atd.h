#ifndef __aphorism_atd__
#define __aphorism_atd__
// ��������� �������� ������ shape
#include "wisdom_atd.h"
namespace simple_wisdom
{
	// �������
	class aphorism : public wisdom
	{
	public:
		char author[50];
		// �������������� ��������� ������
		int InData(ifstream& ifst); // ����
		void Out(ofstream& ofst); // �����
		aphorism() {} // �������� ��� �������������.
	};
}
#endif