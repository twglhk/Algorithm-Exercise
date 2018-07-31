#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;
vector<vector<int>> edge;


void dfs(int cur)
{
	visited[cur] = true;
	//cout << cur << ' ';

	for (int i = 0; i < edge[cur].size(); i++)
	{
		int there = edge[cur][i];

		if (visited[there]) continue;
		
		dfs(there);
	}
}

int main()
{
	int computer, pnum; 
	int result = 0;

	cin >> computer;

	if (computer > 100 || computer < 0)
		exit(1);

	visited.resize(computer+1);
	edge.resize(computer+1);

	cin >> pnum;

	for (int i = 0; i < pnum; i++)
	{
		pair<int, int> temp;
		cin >> temp.first >> temp.second;
		
		edge[temp.first].push_back(temp.second);
		edge[temp.second].push_back(temp.first);
	}

	dfs(1);

	for (int j = 2; j < visited.size(); j++)
	{
		//cout << "j =" <<  j << ' ';
		if (visited[j]) result++;
	}

	//cout << endl;

	cout << result << endl;

	return 0;
}


