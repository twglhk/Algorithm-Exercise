#include <iostream>
#include <queue>

using namespace std;

int n, k;
queue<unsigned long long> result;

int main()
{
	while (true)
	{
		cin >> n >> k;

		if (n == 0 && k == 0)
			break;

		if (k > n - k)
			k = n - k;

		unsigned long long temp = 1; // nC0 = 1
		for (int i = 1; i <= k; i++)
		{
			temp = temp * (n-i+1) / i;
		}

		result.push(temp);
	}

	while (!result.empty())
	{
		cout << result.front() << endl;
		result.pop();
	}
		


	return 0;
}