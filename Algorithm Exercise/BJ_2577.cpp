#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int A, B, C;   // �Է� ��
	int result;	   // ���� ���
	int remainder; // parsing vec�� ������ ������
	vector<int> parsing_vec;	// parsing �� ���ڵ��� ���� vector
	int answer[10] = { 0 }; // �� �ڸ��� ���� ī��Ʈ�� ������� ���� �迭

	// Input
	cin >> A >> B >> C;

	// Calculation
	result = A * B * C;
	
	//cout << "�� ��� : " << result << endl;

	// Parsing
	while (result >= 10)
	{
		remainder = result % 10;
		parsing_vec.push_back(remainder);
		result /= 10;
	}

	// ���� �� �� ���� Ǫ��
	parsing_vec.push_back(result);

	// Counting the number of each digit
	while (!parsing_vec.empty())
	{
		answer[parsing_vec.back()]++;
		parsing_vec.pop_back();
	}

	for (int i = 0; i < 10; i++)
		cout << answer[i] << endl;


	return 0;
}