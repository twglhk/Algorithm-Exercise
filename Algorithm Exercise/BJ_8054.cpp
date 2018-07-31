#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> bills;
int cursor;
int total_prize;

int minHeap()
{
	int min;

	// min heap
	for (int i = 1; i <= cursor; i++)
	{
		for (int j = i; j > 1; j /= 2)
		{
			if (bills[j] < bills[j / 2])
				swap(bills[j], bills[j / 2]);
		}
	}

	min = bills[1];

	// delete
	bills[1] = bills[cursor--];
	return min;
}

int maxHeap()
{
	int max;

	// max heap
	for (int i = 1; i <= cursor; i++)
	{
		for (int j = i; j > 1; j /= 2)
		{
			if (bills[j] > bills[j / 2])
				swap(bills[j], bills[j / 2]);
		}
	}

	max = bills[1];
	
	// delete
	bills[1] = bills[cursor--];
	return max;
}

int main()
{
	int days, k; 
	// days -promotion days
	// k - the number of bills

	// Init
	total_prize = 0;
	cursor = 0;
	bills.resize(300000);

	cin >> days;

	while (days--)
	{
		cin >> k;

		while (k--)
		{
			int temp;
			cin >> temp;

			// input bills per days
			bills[++cursor] = temp;
		}

		// STEP 1. Checks at least two more bills in box
		if (cursor < 2)
			continue;

		// STEP 2. Peeks max value with max heap func.
		// STEP 3. Peeks min value with min heap func.
		// STEP 4. Saves value that is defference with max and min value to toal prize. 
		total_prize += maxHeap() - minHeap();

		// Repeat above steps

	}

	 // print out total_prize
	cout << total_prize << endl;

	return 0;
}