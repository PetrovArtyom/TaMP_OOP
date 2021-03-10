#ifndef __container_atd__
#define __container_atd__
#include "wisdom_atd.h"
namespace simple_wisdom 
{
	// ���������� ��������� �� ������ ����������� �������
	class container 
	{
		enum { max_len = 100 }; // ������������ �����
		int len; // ������� �����
		wisdom* cont[max_len];

	public:
		void In(ifstream& ifst); // ����
		void Out(ofstream& ofst); // �����
		void Out_proverb(ofstream& ofst);       // ������������� �����
		container(); // ������������� ����������
		void Clear(); // ������� ����������
		void Sort();  // ���������� ����������
		~container() { Clear(); } // ���������� ����������
	};
}
#endif
