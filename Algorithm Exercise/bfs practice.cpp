#include <iostream>
#include <vector>
#include <queue>

using namespace std;
std::vector<std::vector<int>> edge;
std::vector<bool> visited;

void bfs(int cur)
{
	std::queue<int> q;
	visited[cur] = true;
	q.push(cur);

	while (!q.empty())
	{
		int here = q.front();
		q.pop();

		for (int i = 0; i < edge[here].size(); ++i)
		{
			int there = edge[here][i];
			if (visited[there]) continue;
			visited[there] = true;
			q.push(there);
		}
	}
}


int main()
{

	return 0;
}