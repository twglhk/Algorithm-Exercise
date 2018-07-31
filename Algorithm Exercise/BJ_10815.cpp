#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
vector<int> target;
int n, m;

void quickSort(int left, int right) {
	int pivot, left_temp, right_temp;
	left_temp = left;
	right_temp = right;
	pivot = arr[left];
	while (left < right) {
		while (arr[right] >= pivot && (left < right)) {
			right--;
		}
		if (left != right) {
			arr[left] = arr[right];
		}
		while (arr[left] <= pivot && (left < right)) {
			left++;
		}
		if (left != right) {
			arr[right] = arr[left];
			right--;
		}
	}
	arr[left] = pivot;
	pivot = left;
	left = left_temp;
	right = right_temp;
	if (left < pivot) quickSort(left, pivot - 1);
	if (right > pivot) quickSort(pivot + 1, right);
}

bool bSearch(int val)
{
	int l = 0;
	int r = n - 1;
	
	while (l <= r)
	{
		int mid = (l + r) / 2;
		
		if (val == arr[mid]) return true;
		
		else if (val < arr[mid])
			r = mid - 1;
		
		else l = mid + 1;
	}


	return false;
}


int main()
{
	// the number of cards
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num1;
		cin >> num1;

		arr.push_back(num1);
	}

	quickSort(0, n - 1);

	// test quick sort ok
	/*for (int k = 0; k < n; k++)
	{
		cout << arr[k] << " ";
	}*/

	cin >> m;
	for (int j = 0; j < m; j++)
	{
		int num2;
		cin >> num2;

		target.push_back(num2);
	}

	for (int k = 0; k < target.size(); k++)
	{
		if (bSearch(target[k]))
			cout << '1';

		else
			cout << '0';

		cout << " ";
	}

	//cout << endl;

	return 0;
}