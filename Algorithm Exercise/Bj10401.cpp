#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


vector<vector<int>> graph;
vector<bool> visited;
vector<int> result;


void dfs (int cur)
{
	visited[cur] = true;

	for (int i = 0; i < graph[cur].size(); i++)
	{
		int there = graph[cur][i];
		if (visited[there]) continue;
		dfs(there);
	}
}


// return true when all vertex is visited
// return false when at least, one vertex is not visited
bool checkVisited(int * index_)
{
	for (int i = 1; i < visited.size(); i++)
		if (!visited[i])
		{
			*index_ = i;
			return false;
		}

	return true;
}


int main()
{
	int testcase;

	cin >> testcase;
	
	for (int i = 0; i < testcase; i++)
	{
		int num;
		cin >> num;

		graph.clear();
		graph.resize(num+1);
		visited.clear();
		visited.resize(num + 1);

		for (int j = 1; j < graph.size() ; j++)
		{
			int input;
			cin >> input;

			graph[j].push_back(input);
		}


		int index = 1;
		int cycleNum = 0;

		while (!checkVisited(&index))
		{
			dfs(index);
			cycleNum++;
		}

		result.push_back(cycleNum);

		// test
		/*for (int k = 1; k < graph.size(); k++)
		{
			cout << graph[k].front() << " ";
			cout << endl;
		}*/
	}

	vector<int>::iterator iter;
	for (iter = result.begin(); iter != result.end(); iter++)
		cout << *iter << endl;


	return 0;
}