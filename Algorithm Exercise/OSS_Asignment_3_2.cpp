#include <iostream>
#include <vector>
#include <string>

using namespace std;

std::vector<vector<int>> graph;
std::vector<bool> visited; 

std::vector<int> answer; // 한 케이스의 답
std::vector<vector<int>> answerArr; // 출력을 위한 답 vector를 저장할 vector

int T, N;
int excepted;

void dfs(int cur)
{
	visited[cur] = true;  // 현재 위치 방문 처리
	int there;            // 다음 방문할 곳

	// 한 노드와 연결된 모든 노드 탐색
	for (int i = 0; i < graph[cur].size(); i++)
	{
		there = graph[cur][i];

		// 방문 했거나 제외한 노드면 스킵
		if (visited[there] || there == excepted)
			continue;
		
		// 방문 안 했다면 그 노드부터 DFS 재귀
		dfs(there);
	}
}

void parsingString(std::string& str)
{
	// Edge parsing and graph init
	bool pairCheck = false;
	std::pair<int, int> node;

	for (auto& ch : str)
	{
		if (ch == ' ')
			continue;

		else
		{
			switch (pairCheck)
			{
			case true:
				node.second = ch - '0';
				graph[node.first].push_back(node.second);
				graph[node.second].push_back(node.first);
				pairCheck = false;
				break;

			case false:
				node.first = ch - '0';
				pairCheck = true;
				break;

			default:
				break;
			}
		}
	}
}


int main()
{
	cin >> T;

	while (T--)
	{
		std::string edge; // 연결 정보를 받을 문자열

		cin >> N;

		std::cin.ignore();
		std::getline(cin, edge);
		
		// clear and resize array
		graph.clear();
		visited.clear();
		answer.clear();

		graph.resize(N + 1);
		visited.resize(N + 1, false);
		answer.resize(0);


		// Pasing
		parsingString(edge);

		// 하나씩 노드를 제외하고 DFS
		for (int i = 1; i < graph.size(); i++)
		{
			excepted = i%N +1; // 제외할 노드
			dfs(i);            // 탐색. 제외한 노드는 탐색하지 않음. 다 탐색을 못 할 경우 cutnode
			
			// 다 방문 했나 탐색
			for (int j = 1; j < visited.size(); j++)
			{
				// 제외 노드는 패스
				if (j == excepted)
					continue;

				// 방문 안 한 노드가 있다면
				else if (visited[j] == false)
				{
					answer.push_back(excepted); // 답 저장
					break;
				}
			}


			// visited vector 클리어 및 초기화
			visited.clear();
			visited.resize(N + 1, false);
		}

		answerArr.push_back(answer); // 답 저장
	}

	// print
	for (int i = 0; i < answerArr.size(); i++)
	{
		cout << "Case#" << i + 1 << " : ";
		
		for (int j = 0; j < answerArr[i].size(); j++)
			cout << answerArr[i][j] << " ";

		cout << endl;
	}

	return 0;
}