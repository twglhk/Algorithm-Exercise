#include "CustomAlgol.h"

using namespace std;


std::string g_sNum;  // �Է� ���� ���� ����
int g_nOriginNum;
int g_nHiddenPW[4] = { 0, }; // ���Ű msnt
int g_nMultiple = 1; // ���


int main()
{	
	cin >> g_sNum;
	g_nOriginNum = atoi(g_sNum.c_str());

	while (true)
	{
		std::pair<char, char> nBipNum;

		// parsing and count
		for (auto& number : g_sNum)
		{
			

			// 1 ��° ������ ���. (������ ���� string�� at�� ����ұ� ������ �׳� ����.)
			if (nBipNum.first == NULL)
			{
				nBipNum.first = number;
				g_nHiddenPW[1] = number - '0'; // ���� pair�� ���� array�� setting
				g_nHiddenPW[0]++;			   // 1 ��° ���� count ����
				continue;
			}

			// 1 ��° ���ڿ� ������ ������ ���
			else if (nBipNum.second == NULL)
			{
				// 1 ��° ���ڿ� ���ӵ� �����
				if (number == nBipNum.first)
				{
					g_nHiddenPW[0]++; // 1 ��° ���� count ����
					continue;
				}

				// ���ӵ��� ���� ���ο� ���ڰ� ���� ���
				else
				{
					nBipNum.second = number;     // �񱳿� pair�� setting
					g_nHiddenPW[3] = number-'0'; // ���Ű�� 2��° �� setting
					g_nHiddenPW[2]++;            // 2��° ���� count ����
				}
			}

			// �� ���ڰ� ��� ���� ���
			else
			{
				// 2 ��° ���ڿ� �ٸ� ���� ���Դٸ�
				if (number != nBipNum.second)
				{
					break;
				}

				// 2 ��° ���ڿ� �����̶��
				else
				{
					g_nHiddenPW[2]++;            // 2��° ���� count ����
					continue;
				}
			}
		}

		// �Ľ��� ����� ������ ������ �����ϴٸ� => �̺м��� ���Դٸ�
		if (g_nHiddenPW[0] + g_nHiddenPW[2] == g_sNum.size())
		{
			for (auto& answer : g_nHiddenPW)
				cout << answer << " ";

			break;
		}

		// �̺м��� �� ���Դٸ�
		else
		{
			int temp;
			temp = atoi(g_sNum.c_str()); // ����� ���ϱ� ���� int�� ��ȯ.
			temp += g_nOriginNum;	     // ��� update
			g_sNum = to_string(temp);    // parsing�� ���� �ٽ� string ��ȯ


			// clear

			nBipNum.first = NULL;
			nBipNum.second = NULL; 

			for (auto& num : g_nHiddenPW)
				num = 0;

		}

	}

	return 0;
}