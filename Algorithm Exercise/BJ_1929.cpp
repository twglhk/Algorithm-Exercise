#include <iostream>
#include <stdio.h>
#include <vector>

#define MAX 1000001 // 0 ~ 1,000,000

using namespace std;

vector<bool> v_bArr(MAX, true); // 소수인지 아닌지를 저장할 벡터
long N, M; // 소수를 출력할 범위

void Eratosthenes()
{
	for (long i = 2; i <= M; i++)
	{
		if (!v_bArr[i])
			continue;

		if (i >= N)
			printf("%d\n", i);

		for (long j = i + i; j <= M; j += i)
		{
			v_bArr[j] = false;
		}
			
	}
}

int main()
{
	cin >> N >> M;
	Eratosthenes();

	return 0;
}