#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	const int mod = 1000000;
	const int p = 1500000;
	//int fibo[p] = { 0,1 };
	vector<int> fibo;
	fibo.resize(p);
	fibo[0] = 0;
	fibo[1] = 1;

	long long n;
	cin >> n;

	for (int i = 2; i<p; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		fibo[i] %= mod;
	}

	cout << fibo[n%p] << '\n';
	
	return 0;
}