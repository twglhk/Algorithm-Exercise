#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<int> A;
std::vector<int> B;
std::vector<int> merged_vector;
int N, M;

void Input_vector(std::vector<int>& vec_, int& temp)
{
	vec_.push_back(temp);
}


void merge(const std::vector<int>& a_, const std::vector<int>& b_)
{

	int i = 0; // vector A iterator
	int j = 0; // vector B iterator

	while (true)
	{
		if (a_[i] < b_[j]) { merged_vector.push_back(a_[i++]); }
		else if (a_[i] > b_[j]) { merged_vector.push_back(b_[j++]); }
		else
		{
			// same elements
			merged_vector.push_back(a_[i++]);
			j++;
		}

		if (i == a_.size())
		{
			for (; j < b_.size(); j++)
				merged_vector.push_back(b_[j]);

			break;
		}

		else if (j == b_.size())
		{
			for (; i < a_.size(); i++)
				merged_vector.push_back(a_[i]);

			break;
		}
	}
}



int main()
{
	int temp;

	cin >> N >> M;


	// input 
	while (N--)
	{
		cin >> temp;
		Input_vector(A, temp);
	}

	while (M--)
	{
		cin >> temp;
		Input_vector(B, temp);
	}

	// Sorting
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	// Two pointer Merge
	merge(A, B);

	// pirnt
	for (auto& number : merged_vector)
	{
		cout << number << " ";
	}

	cout << endl;


	return 0;
}