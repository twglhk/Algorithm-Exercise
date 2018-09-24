#include "CustomAlgol.h"

using namespace std;


std::string g_sNum;  // 입력 받을 양의 정수
int g_nOriginNum;
int g_nHiddenPW[4] = { 0, }; // 비밀키 msnt
int g_nMultiple = 1; // 배수


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
			

			// 1 번째 숫자의 경우. (밖으로 빼고 string의 at을 사용할까 했으나 그냥 넣음.)
			if (nBipNum.first == NULL)
			{
				nBipNum.first = number;
				g_nHiddenPW[1] = number - '0'; // 비교할 pair와 정답 array에 setting
				g_nHiddenPW[0]++;			   // 1 번째 수의 count 증가
				continue;
			}

			// 1 번째 숫자와 연속인 구간의 경우
			else if (nBipNum.second == NULL)
			{
				// 1 번째 숫자와 연속된 수라면
				if (number == nBipNum.first)
				{
					g_nHiddenPW[0]++; // 1 번째 수의 count 증가
					continue;
				}

				// 연속되지 않은 새로운 숫자가 들어온 경우
				else
				{
					nBipNum.second = number;     // 비교용 pair에 setting
					g_nHiddenPW[3] = number-'0'; // 비밀키에 2번째 수 setting
					g_nHiddenPW[2]++;            // 2번째 수의 count 증가
				}
			}

			// 두 숫자가 모두 들어온 경우
			else
			{
				// 2 번째 숫자와 다른 수가 나왔다면
				if (number != nBipNum.second)
				{
					break;
				}

				// 2 번째 숫자와 연속이라면
				else
				{
					g_nHiddenPW[2]++;            // 2번째 수의 count 증가
					continue;
				}
			}
		}

		// 파싱한 결과가 숫자의 갯수와 동일하다면 => 이분수가 나왔다면
		if (g_nHiddenPW[0] + g_nHiddenPW[2] == g_sNum.size())
		{
			for (auto& answer : g_nHiddenPW)
				cout << answer << " ";

			break;
		}

		// 이분수가 안 나왔다면
		else
		{
			int temp;
			temp = atoi(g_sNum.c_str()); // 배수를 구하기 위해 int로 변환.
			temp += g_nOriginNum;	     // 배수 update
			g_sNum = to_string(temp);    // parsing을 위해 다시 string 변환


			// clear

			nBipNum.first = NULL;
			nBipNum.second = NULL; 

			for (auto& num : g_nHiddenPW)
				num = 0;

		}

	}

	return 0;
}