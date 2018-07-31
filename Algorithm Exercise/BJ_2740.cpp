#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrixA;
vector<vector<int>> matrixB;
vector<vector<int>> result;

int main()
{
	int n, m1, m2, k;

	cin >> n >> m1;

	matrixA.resize(n);
	matrixB.resize(m1);

	for (int i = 0; i < n; i++)
	{
		matrixA[i].resize(m1);

		for (int j = 0; j < m1; j++)
			cin >> matrixA[i][j];
	}

	// test : input matrixA - ok

	cin >> m2 >> k;

	if (m1 != m2)
		return 0;

	result.resize(n);
	for (int i = 0; i < n; i++)
		result[i].resize(k);

	
	for (int i = 0; i < m2; i++)
	{
		matrixB[i].resize(k, 0);
		
		for (int j = 0; j < k; j++)
			cin >> matrixB[i][j];
	}
	
	// test : input matrixB - ok
	
	for (int i =0; i<n; i++)
		for (int j = 0; j < k; j++)
			for (int z = 0; z < m1; z++)
			{
				result[i][j] += matrixA[i][z] * matrixB[z][j];
			}


	for (int i = 0; i < n; i++)
	{
	
		for (int j = 0; j < k; j++)
			cout << result[i][j] << " ";
		
	}
		
	cout << endl;

	return 0;
}