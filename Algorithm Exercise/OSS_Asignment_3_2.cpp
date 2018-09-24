#include <iostream>
#include <vector>
#include <string>

using namespace std;

std::vector<vector<int>> graph;
std::vector<bool> visited; 

std::vector<int> answer; // �� ���̽��� ��
std::vector<vector<int>> answerArr; // ����� ���� �� vector�� ������ vector

int T, N;
int excepted;

void dfs(int cur)
{
	visited[cur] = true;  // ���� ��ġ �湮 ó��
	int there;            // ���� �湮�� ��

	// �� ���� ����� ��� ��� Ž��
	for (int i = 0; i < graph[cur].size(); i++)
	{
		there = graph[cur][i];

		// �湮 �߰ų� ������ ���� ��ŵ
		if (visited[there] || there == excepted)
			continue;
		
		// �湮 �� �ߴٸ� �� ������ DFS ���
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
		std::string edge; // ���� ������ ���� ���ڿ�

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

		// �ϳ��� ��带 �����ϰ� DFS
		for (int i = 1; i < graph.size(); i++)
		{
			excepted = i%N +1; // ������ ���
			dfs(i);            // Ž��. ������ ���� Ž������ ����. �� Ž���� �� �� ��� cutnode
			
			// �� �湮 �߳� Ž��
			for (int j = 1; j < visited.size(); j++)
			{
				// ���� ���� �н�
				if (j == excepted)
					continue;

				// �湮 �� �� ��尡 �ִٸ�
				else if (visited[j] == false)
				{
					answer.push_back(excepted); // �� ����
					break;
				}
			}


			// visited vector Ŭ���� �� �ʱ�ȭ
			visited.clear();
			visited.resize(N + 1, false);
		}

		answerArr.push_back(answer); // �� ����
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