
/*

<�׸� 1>�� ���� ���簢�� ����� ������ �ִ�. 1�� ���� �ִ� ����, 0�� ���� ���� ���� ��Ÿ����. 

ö���� �� ������ ������ ����� ������ ������ ������ �����ϰ�, 

������ ��ȣ�� ���̷� �Ѵ�. ���⼭ ����Ǿ��ٴ� ���� � ���� �¿�, Ȥ�� �Ʒ����� �ٸ� ���� �ִ� ��츦 ���Ѵ�. 

�밢���� ���� �ִ� ���� ����� ���� �ƴϴ�. <�׸� 2>�� <�׸� 1>�� �������� ��ȣ�� ���� ���̴�. 

������ �Է��Ͽ� �������� ����ϰ�, �� ������ ���ϴ� ���� ���� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.


�Է�
ù ��° �ٿ��� ������ ũ�� N(���簢���̹Ƿ� ���ο� ������ ũ��� ������ 5��N��25)�� �Էµǰ�, 
�� ���� N�ٿ��� ���� N���� �ڷ�(0Ȥ�� 1)�� �Էµȴ�.

���
ù ��° �ٿ��� �� �������� ����Ͻÿ�. �׸��� �� ������ ���� ���� ������������ �����Ͽ� �� �ٿ� �ϳ��� ����Ͻÿ�.

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N; // �Է�
int total_complex; // �� ���� ��
vector<vector<bool>> map; // ���� ����
vector<vector<bool>> visited; // �� �湮 ����
vector<int> complex; // ������ �� ���� �� ���� ��


int dfs(int i, int j)
{
	// �ʺ� �켱 Ž��
	// return ���� ������ �� ��, �� �Լ��� ȣ��Ǿ��ٴ� �ǹ̴� ���� �ϳ� �ִٴ� �ǹ� �̹Ƿ� 1�� �ʱ�ȭ
	int houseNum = 1;

	// ���� ��ġ �湮 ó��
	visited[i][j] = true;
	
	// �����¿� ���� ���� Ž��
	// ����, �� ������ �ƴϰ� , ���� �����ϴµ� �湮���� �ʾҴٸ�
	if (i != 0 && map[i-1][j] == 1 && visited[i-1][j] != true)
		houseNum += dfs(i-1,j);

	// ���� ��, �� ���� ���� �ƴϰ�, ���� �����ϴµ�, �湮���� �ʾҴٸ�
	if (j != 0 && map[i][j-1] == 1 && visited[i][j-1] != true)
		houseNum += dfs(i, j-1);


	// �Ʒ���, �� �Ʒ����� �ƴϰ�, ���� �����ϴµ� �湮���� �ʾҴٸ�
	if (i != N-1 && map[i+1][j] == 1 && visited[i+1][j] != true)
		houseNum += dfs(i+1, j);


	// ������ ��, �� ������ ���� �ƴϰ�, ���� �����ϴµ�, �湮���� �ʾҴٸ�
	if (j != N-1 && map[i][j+1] == 1 && visited[i][j+1] != true)
		houseNum += dfs(i, j+1);

	return houseNum;
}


// Quick Sort 
void quickSort(vector<int>& arr, int left, int right) {
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
	if (left < pivot) quickSort(arr, left, pivot - 1);
	if (right > pivot) quickSort(arr, pivot + 1, right);
}



int main()
{
	// Init
	total_complex = 0;

	cin >> N;

	map.resize(N);
	visited.resize(N);

	for (int i = 0; i < N; i++)
	{
		map[i].resize(N);
		visited[i].resize(N, 0);

		string str;

		cin >> str;

		for (int j = 0; j < N; j++)
		{
			// ���� ���� �Ҵ�
			map[i][j] = str.at(j) - '0';
		}
	}

	// print map test
	/*cout << endl;
	for (int i = 0; i < N; i++)
	{
	for (int j = 0; j < N; j++)
	{
	cout << visited[i][j];
	}
	cout << endl;
	}*/


	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// ���� �ְ� �湮�� ���� �ʾҴٸ�
			if (map[i][j] == 1 && visited[i][j] == 0)
			{
				int temp = dfs(i, j);

				// ���� �ϳ���� (����� ���� �����Ƿ� ���� ���� x)
				/*if (temp == 1)
					continue;*/

				// ������ �����Ǿ��ٸ�
				//else
				//{
					// �� ���� ���� ����
					total_complex++;

					// ������ �� �� ����
					complex.push_back(temp);
				//}

			}
				
		}
		
	}
		

	// ���� �� ����
	quickSort(complex, 0, complex.size()-1);

	// print 
	cout << total_complex << endl;

	for (int i =0; i<complex.size(); i++)
		cout << complex[i] << endl;

	/*for (int i = complex.size()-1; i >= 0; i--)
		cout << complex[i] << endl;			*/

	return 0;
}