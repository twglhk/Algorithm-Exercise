#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int A, B, C;   // 입력 값
	int result;	   // 곱의 결과
	int remainder; // 나머지
	int answer[10] = { 0 }; // 각 자릿수 마다 카운트된 결과값을 담을 배열

	// Input
	cin >> A >> B >> C;

	// Calculation
	result = A * B * C;
	
	cout << "곱 결과 : " << result << endl;

	// Parsing and Counting the number of each digit
	while (result >= 10)
	{
		remainder = result % 10;
		answer[remainder]++;
		result /= 10;
	}

	// 마지막 숫자
	answer[result]++;

	for (int i = 0; i < 10; i++)
		cout << answer[i] << endl;


	return 0;
}