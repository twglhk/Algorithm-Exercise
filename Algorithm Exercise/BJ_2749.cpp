#include <iostream>
#include <string>
#include <vector>

using namespace std;

string input;
vector<int> vParsing;
vector<unsigned long long> vFibonacci;

// 피보나치 DP 함수 ( TOP DOWN ) 
unsigned long long fibonacci (int n_)
{
	if (n_ <= 1) return vFibonacci[n_];

	else 
	{
		// 존재하는 경우
		if (vFibonacci.size() > n_)
			return vFibonacci[n_];

		vFibonacci.push_back(fibonacci(n_-1)%1000000 + fibonacci(n_ - 2)%1000000);

		return vFibonacci[n_];
	}
}


int main()
{
	vFibonacci.resize(2);
	vFibonacci[0] = 0;
	vFibonacci[1] = 1;

	cin >> input;
	
	for (int i = input.size() -1 ; i >= 0; i--)
	{
		int temp = input.at(i) - '0';
		vParsing.push_back(temp);
	}

	// 10억 단위
	/*while (vParsing.size() > 9)
	{
		
	}*/

	// 억단위 아래

	int total_sum = 0;

	while (vParsing.size() > 0)
	{
		if (vParsing.back() == 0)
		{
			vParsing.pop_back();
			continue;
		}

		total_sum += vParsing.back() * pow(10, vParsing.size() - 1);
		fibonacci( total_sum );
		vParsing.pop_back();
	}

	
	printf("%u \n", vFibonacci[vFibonacci.size() - 1]);

	return 0;
}