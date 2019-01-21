#include <iostream>
#include <vector>

std::vector<bool> visited;
std::vector<std::vector<int>> edge;

void dfs(int cur)
{
	visited[cur] = true;
	
	for (int i = 0; edge[cur].size(); ++i)
	{
		int there = edge[cur][i];
		if (visited[cur]) continue;
		dfs(there);
	}
}

int main()
{
	

	return 0;
}