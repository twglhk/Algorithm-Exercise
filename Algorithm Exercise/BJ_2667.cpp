
/*

<그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 

철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 

단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 

대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 

지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.


입력
첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 
그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

출력
첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N; // 입력
int total_complex; // 총 단지 수
vector<vector<bool>> map; // 지도 정보
vector<vector<bool>> visited; // 집 방문 정보
vector<int> complex; // 정렬할 각 단지 별 집의 수


int dfs(int i, int j)
{
	// 너비 우선 탐색
	// return 값은 단지내 집 수, 이 함수가 호출되었다는 의미는 집이 하나 있다는 의미 이므로 1로 초기화
	int houseNum = 1;

	// 현재 위치 방문 처리
	visited[i][j] = true;
	
	// 상하좌우 인접 구간 탐색
	// 윗집, 맨 윗줄이 아니고 , 집은 존재하는데 방문하지 않았다면
	if (i != 0 && map[i-1][j] == 1 && visited[i-1][j] != true)
		houseNum += dfs(i-1,j);

	// 왼쪽 집, 맨 왼쪽 줄이 아니고, 집은 존재하는데, 방문하지 않았다면
	if (j != 0 && map[i][j-1] == 1 && visited[i][j-1] != true)
		houseNum += dfs(i, j-1);


	// 아랫집, 맨 아랫줄이 아니고, 집은 존재하는데 방문하지 않았다면
	if (i != N-1 && map[i+1][j] == 1 && visited[i+1][j] != true)
		houseNum += dfs(i+1, j);


	// 오른쪽 집, 맨 오른쪽 줄이 아니고, 집은 존재하는데, 방문하지 않았다면
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
			// 지도 정보 할당
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
			// 집이 있고 방문이 되지 않았다면
			if (map[i][j] == 1 && visited[i][j] == 0)
			{
				int temp = dfs(i, j);

				// 집이 하나라면 (연결된 집이 없으므로 단지 성립 x)
				/*if (temp == 1)
					continue;*/

				// 단지가 형성되었다면
				//else
				//{
					// 총 단지 개수 증가
					total_complex++;

					// 단지의 집 수 저장
					complex.push_back(temp);
				//}

			}
				
		}
		
	}
		

	// 단지 수 정렬
	quickSort(complex, 0, complex.size()-1);

	// print 
	cout << total_complex << endl;

	for (int i =0; i<complex.size(); i++)
		cout << complex[i] << endl;

	/*for (int i = complex.size()-1; i >= 0; i--)
		cout << complex[i] << endl;			*/

	return 0;
}