#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N; // element num;
std::vector<int> A;

int main()
{
	int input;

	cin >> N;

	while (N--)
	{
		cin >> input;
		A.push_back(input);
	}

	// 음수 1개
	for (int i = 0; i < A.size(); i++)
	{
		int first = A[i]; // first pick

		for (int j = i + 1; j < A.size(); j++)
		{
			int second = A[j]; // second pick

			for (int k = j + 1; k < A.size(); k++)
			{
				int third = A[k]; // third pick

				if (first + second + third == 0)
				{
					cout << i << " " << j << " " << k << endl;
					return 0;
				}
			}
		}
	}

	cout << "읎다" << endl;

	return 0;
}
