#include "proverb_atd.h"
using namespace std;
namespace simple_wisdom
{
	// ���� ���������� ��������
	void proverb::InData(ifstream& ifst)
	{
		ifst.getline(content, 200);
		ifst.getline(country, 50);
	}

	int proverb::marks_number()
	{
		int marks_num = 0;
		char marks[] = { '.', ',', '!', '?', '-', ';', ':' };
		int marks_len = 7;

		for (int i = 0; i < strlen(content); i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (content[i] == marks[j])
				{
					marks_num++;
				}
			}
		}

		return marks_num;
	}

	// ����� ���������� ��������
	void proverb::Out(ofstream& ofst)
	{
		ofst << "���������: " << content << endl << "������: " << country << endl;
	}
}
