#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	vector<int>::iterator vIter = vec.end();

	//printf("%x\n", vIter);
	cout << *(vIter-1) << endl;
	//cout << *(--vIter) << endl;
	//cout << *(vIter - 1) << endl;

	//vIter -= 1;

	//cout << *vIter + 1<< endl;

	return 0;
}