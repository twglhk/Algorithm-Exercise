#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_SIZE 100000

int N; // input, the number of Nodes
std::vector<vector<int>> tree(MAX_SIZE+1); // Graph
std::vector<int> vParent(MAX_SIZE+1); // Parent node array

void seach(int& nIndex_)
{

}

int main()
{
	cin >> N;

	for (int i = 0, std::pair<int, int> temp_pair; i < N; i++)
	{
		cin >> temp_pair.first >> temp_pair.second;
		tree[temp_pair.first].push_back(temp_pair.second);
	}

	for (int i = 1; tree ; i++)
	{
		for (int j = 0; j < tree[i].size(); j++)
		{
			cout << tree[i][j] << " ";
		}
		cout << endl;
	}
			

	return 0;
}