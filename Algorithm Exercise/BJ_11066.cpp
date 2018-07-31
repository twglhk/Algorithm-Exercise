#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> file;
vector<int> result;
deque<int> d;
pair<int, int> min_index_and_sum;

void compile()
{
	if (file.size() == 1)
	{
		return;
	}

	for (int i = 0; i < file.size(); i++)
		cout << file[i] << " ";

	cout << endl;


	// build first floor
	for (int i = 0; i < file.size()-1; i++)
	{
		d.push_back(file[i] + file[i + 1]);
	}

	for (int i = 0; i < d.size(); i++)
		cout << d[i] << " ";

	cout << endl;

	min_index_and_sum.first = 0;
	min_index_and_sum.second = d[0];

	// min find
	for (int j = 1 ; j < d.size(); j++)
	{
		if (min_index_and_sum.second > d[j])
		{
			min_index_and_sum.first = j;
			min_index_and_sum.second = d[j];
		}
	}

	// save result
	result.push_back(min_index_and_sum.second);
	cout << "flag = " << min_index_and_sum.second << endl;

	// DP
	deque<int> temp;
	//temp.resize(d.size()-2);

	if (d.size() == 1)
	{
		temp.push_back(d[0]);
	}

	else if (min_index_and_sum.first == 0)
	{
		temp.push_back(d[0]);
		temp.push_back(d[1] - file[1]);

		for (int i = 2; i < d.size(); i++)
		{
			temp.push_back(d[i]);
		}
	}

	else if (min_index_and_sum.first == d.size() - 1)
	{
		temp.push_front(d[d.size() - 1]);
		temp.push_front(d[d.size() - 2] - file[file.size() - 2]);

		for (int i = d.size() - 3; i >= 0; i--)
			temp.push_front(d[i]);
	}

	else
	{
		for (int i = min_index_and_sum.first-2; i >= 0; i--)
			temp.push_front(d[i]);

		temp.push_back(d[min_index_and_sum.first - 1] - file[min_index_and_sum.first]);
		temp.push_back(d[min_index_and_sum.first]);
		temp.push_back(d[min_index_and_sum.first + 1] - file[min_index_and_sum.first + 1]);

		for (int j = min_index_and_sum.first + 2; j < d.size(); j++)
			temp.push_back(d[j]);
	}

	file.clear();
	d.clear();

	// Create New File for top-down
	for (int k = 0; k < temp.size(); k++)
		file.push_back(temp[k]);

	compile();
}

int main()
{
	int t, k;
	
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		file.clear();
		d.clear();
		result.clear();

		cin >> k;

		for (int j = 0; j < k; j++)
		{
			int temp;
			cin >> temp;
			file.push_back(temp);
		}

		// do compile
		compile();

		int answer = 0;
		for (int i = 0; i < result.size(); i++)
		{
			answer += result[i];
		}

		cout << answer << endl;
	}

	return 0;
}