#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int A, B, C;   // �Է� ��
	int result;	   // ���� ���
	int remainder; // ������
	int answer[10] = { 0 }; // �� �ڸ��� ���� ī��Ʈ�� ������� ���� �迭

	// Input
	cin >> A >> B >> C;

	// Calculation
	result = A * B * C;
	
	cout << "�� ��� : " << result << endl;

	// Parsing and Counting the number of each digit
	while (result >= 10)
	{
		remainder = result % 10;
		answer[remainder]++;
		result /= 10;
	}

	// ������ ����
	answer[result]++;

	for (int i = 0; i < 10; i++)
		cout << answer[i] << endl;


	return 0;
}