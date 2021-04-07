#ifndef __wisdom_atd__
#define __wisdom_atd__
#include <fstream>
using namespace std;
namespace simple_wisdom
{
	class wisdom
	{
	public:
		char content[200];

		// �������������, ���������� � ���� ������ �� ������
		static wisdom* In(ifstream& ifst);
		virtual void InData(ifstream& ifst) = 0; // ����
		virtual void Out(ofstream& ofst) = 0; // �����
		virtual void MultiMethod(wisdom* other, ofstream& ofst) = 0;	// ���������
		virtual void MM_Aphorism(ofstream& ofst) = 0;					// ������� ������ ���� � ���������
		virtual void MM_Proverb(ofstream& ofst) = 0;					// ������� ������ ���� � ����������
	};
}
#endif
