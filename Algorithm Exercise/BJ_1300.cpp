#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v_nArray;		   // 1차원 배열

int N; // 배열 사이즈(입력값)
int K; // 찾을 순번의 숫자

int main()
{
	cin >> N >> K;
	v_nArray.resize((N*N)+1);

	for (int i = 1, cursor = 1; i <= N; i++)
	{
		// 초기화
		for (int j = 1; j <= N; j++)
			v_nArray[cursor++] = i * j;
	}

	// Sorting array
	sort(v_nArray.begin(), v_nArray.end());
	
	// Print test
	/*for (int i = 1; i < v_nArray.size(); i++)
		cout << v_nArray[i] << " ";

	cout << endl;*/

	cout << v_nArray[K] << endl;

	return 0;
}