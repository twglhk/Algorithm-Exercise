#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s = "ABCDE";
	string temp = s.substr(0, 3);
	cout << s << " " << temp << endl;

	return 0;
}