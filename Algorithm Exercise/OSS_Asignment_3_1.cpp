#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

std::vector<int> arr;
std::vector<int> answer;
int T,N;
int roundNum;

void printArr()
{
	for (const auto& num : arr)
		cout << num << " ";
	
	cout << endl;
}

int main()
{
	cin >> T;

	while(T--)
	{
		// Input
		cin >> N;
		arr.resize(N);
		roundNum = 0;

		// arr input
		for (int j = 0; j < N; j++)
		{
			cin >> arr[j];
		}

		while (N != 1)
		{
			// Max var init
			int max = arr[0];
			int maxIndex = 0;


			// find max
			for (int k = 1; k < N; k++)
			{
				if (arr[k] > max)
				{
					max = arr[k];
					maxIndex = k;
				}
			}

			
			// check already sorted item or not
			if (maxIndex == N-1)
			{
				N--;
				continue;
			}
				
			// Sorting
			while (maxIndex != N - 1)
			{
				swap(arr[maxIndex], arr[maxIndex + 1]);
				//printArr();
				maxIndex++;
			}
			
			roundNum++;
			N--;
		}

		answer.push_back(roundNum); // answer save
		arr.clear(); // clear array
	}

	
	for (int i =0; i<answer.size(); i++)
		cout << "Case #" << i+1 << " Round : " << answer[i] << endl;

	return 0;
}