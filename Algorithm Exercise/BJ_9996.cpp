/*
������ ���ĺ� �ҹ��� ���� ���� ��ǥ(*) �ϳ��� �̷���� ���ڿ��̴�.

���� �̸��� ���Ͽ� ��ġ�Ϸ���, ���Ͽ� �ִ� ��ǥ�� ���ĺ� �ҹ��ڷ� �̷���� ������ ���ڿ��� ��ȯ�� ���� �̸��� ���� ���� �� �־�� �Ѵ�. ��ǥ�� �� ���ڿ��� �ٲ� ���� �ִ�. ���� ���, "abcd", "ad", "anestonestod"�� ��� ���� "a*d"�� ��ġ�Ѵ�. ������, "bcd"�� ��ġ���� �ʴ´�.

���ϰ� ���� �̸��� ��� �־����� ��, ������ ���� �̸��� ���ϰ� ��ġ�ϴ��� �ƴ����� ���ϴ� ���α׷��� �ۼ��Ͻ�



�Է�

ù° �ٿ� ������ ���� N�� �־�����. (1 �� N �� 100)

��° �ٿ��� ������ �־�����. ������ ���ĺ� �ҹ��ڿ� ��ǥ(�ƽ�Ű�� 42) �� ���� �̷���� �ִ�. ���ڿ��� ���̴� 100�� ���� ������, ��ǥ�� ���ڿ��� ���۰� ���� ���� �ʴ�.

���� N�� �ٿ��� ���� �̸��� �־�����. ���� �̸��� ���ĺ� �ҹ��ڷθ� �̷���� �ְ�, ���̴� 100�� ���� �ʴ´�.




���

�� N���� �ٿ� ���ļ�, �Է����� �־��� i��° ���� �̸��� ���ϰ� ��ġ�ϸ� "DA", ��ġ���� ������ "NE"�� ����Ѵ�.

�����, "DA"�� ũ�ξ�Ƽ���� "YES"��, "NE"�� "NO"�� �ǹ��Ѵ�.


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