#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int n, k;
queue<int> result;
vector<int> denominator;
deque<int> numerator;

int factorial()
{
	numerator.clear();
	denominator.clear();

	for (int i = 0; i < k; i++)
	{
		denominator.push_back(n--);
		numerator.push_back(k-i);
	}

	while (!numerator.empty())
	{
		if (numerator.front() == 1)
		{	
			numerator.pop_front();
		}

		else
		{
			for (int i = denominator.size()-1; i >=0; i--)
			{
				if (denominator[i] % numerator.front() == 0)
				{
					denominator[i] /= numerator.front();
					numerator.pop_front();
					break;
				}
			}
		}
	}


	int temp = 1;

	for (int i = 0; i < denominator.size(); i++)
		temp *= denominator[i];
		
	return temp;
}



int main()
{
	while (true)
	{
		cin >> n >> k;

		if (n == 0 && k == 0)
			break;

		if (k <= n - k)
		{
			// combination
			result.push(factorial());
		}

		else
		{
			k = n - k;
			// combination
			result.push(factorial());
		}

	}

	while (!result.empty())
	{
		cout << result.front() << endl;
		result.pop();
	}
		


	return 0;
}