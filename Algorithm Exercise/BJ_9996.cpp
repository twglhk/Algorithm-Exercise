/*
패턴은 알파벳 소문자 여러 개와 별표(*) 하나로 이루어진 문자열이다.

파일 이름이 패턴에 일치하려면, 패턴에 있는 별표를 알파벳 소문자로 이루어진 임의의 문자열로 변환해 파일 이름과 같게 만들 수 있어야 한다. 별표는 빈 문자열로 바꿀 수도 있다. 예를 들어, "abcd", "ad", "anestonestod"는 모두 패턴 "a*d"와 일치한다. 하지만, "bcd"는 일치하지 않는다.

패턴과 파일 이름이 모두 주어졌을 때, 각각의 파일 이름이 패턴과 일치하는지 아닌지를 구하는 프로그램을 작성하시



입력

첫째 줄에 파일의 개수 N이 주어진다. (1 ≤ N ≤ 100)

둘째 줄에는 패턴이 주어진다. 패턴은 알파벳 소문자와 별표(아스키값 42) 한 개로 이루어져 있다. 문자열의 길이는 100을 넘지 않으며, 별표는 문자열의 시작과 끝에 있지 않다.

다음 N개 줄에는 파일 이름이 주어진다. 파일 이름은 알파벳 소문자로만 이루어져 있고, 길이는 100을 넘지 않는다.




출력

총 N개의 줄에 걸쳐서, 입력으로 주어진 i번째 파일 이름이 패턴과 일치하면 "DA", 일치하지 않으면 "NE"를 출력한다.

참고로, "DA"는 크로아티어어로 "YES"를, "NE"는 "NO"를 의미한다.


*/

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N; // the number of words
string pattern;
pair<string, string> parsedPattern;
queue<string> fileName;

// Push target file's name to queue
void InputQueue()
{
	string temp;
	cin >> temp;
	fileName.push(temp);
}


// Parses pattern to front section and back one
void PatternParsing()
{
	string front, back;
	int i = 0;

	// Define front section
	for (; pattern.at(i) != '*'; i++)
		front += pattern.at(i);

	i++; // skip char '*'

	// Define back section
	for (; i < pattern.size(); i++)
		back += pattern.at(i);

	parsedPattern.first = front;
	parsedPattern.second = back;

}


int main()
{
	// Input section
	cin >> N >> pattern;
	while (N--) { InputQueue();}

	// Pattern parsing
	PatternParsing();

	// Parsing func test print
	//cout << parsedPattern.first << " " << parsedPattern.second << endl;


	// Judging if string is corresponded with the pattern
	while (!fileName.empty())
	{
		pair<bool, bool> b_Pcheck = { true, true };

		// Size checks. If a file name's length is too shorter than patterns one, 
		// It should be judged impossible thing.
		if (fileName.front().size() < parsedPattern.first.size() + parsedPattern.second.size())
		{
			cout << "NE" << endl;
			fileName.pop();
			continue;
		}

		// front section
		for (int i = 0; i < parsedPattern.first.size(); i++)
		{
			if (fileName.front().at(i) != parsedPattern.first.at(i))
			{
				b_Pcheck.first = false;
				break;
			}
		}

		// back section
		int nTempSize = fileName.front().size() -1;	// File's index needs to starts from end
		for (int j = parsedPattern.second.size() - 1; j >= 0; j--)
		{
			if (fileName.front().at(nTempSize--) != parsedPattern.second.at(j))
			{
				b_Pcheck.second = false;
				break;
			}
		}

		// Result print section
		if (b_Pcheck.first && b_Pcheck.second)
			cout << "DA" << endl;

		else
			cout << "NE" << endl;
		

		// Pop processed filename
		fileName.pop();
	}

	return 0;
}