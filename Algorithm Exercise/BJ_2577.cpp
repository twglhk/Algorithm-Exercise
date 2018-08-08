#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int A, B, C;   // 입력 값
	int result;	   // 곱의 결과
	int remainder; // parsing vec에 저장할 나머지
	vector<int> parsing_vec;	// parsing 된 숫자들을 담을 vector
	int answer[10] = { 0 }; // 각 자릿수 마다 카운트된 결과값을 담을 배열

	// Input
	cin >> A >> B >> C;

	// Calculation
	result = A * B * C;
	
	//cout << "곱 결과 : " << result << endl;

	// Parsing
	while (result >= 10)
	{
		remainder = result % 10;
		parsing_vec.push_back(remainder);
		result /= 10;
	}

	// 남은 맨 앞 숫자 푸쉬
	parsing_vec.push_back(result);

	// Counting the number of each digit
	while (!parsing_vec.empty())
	{
		answer[parsing_vec.back()]++;
		parsing_vec.pop_back();
	}

	for (int i = 0; i < 10; i++)
		cout << answer[i] << endl;


	return 0;
}