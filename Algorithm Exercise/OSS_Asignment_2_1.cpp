#include <iostream>
#include <string>
#include <math.h>
#include <array>

using namespace std;

std::array<int, 7> odd_month = { 1,3,5,7,8,10,12 }; // 31�ϱ��� �ִ� ��
enum MONTH { ODD, EVEN, FEBRUARY , LEAF }; // 31�ϴ�, 30�ϴ�, 2��, ����

typedef struct Date
{
	int year, month, day;
}Date;


// ���� üũ �Լ�
bool IsLeapYear(int& year_)
{
	if (year_ % 4 == 0)
		return true;

	else
		return false;
}


// 31�ϱ��� �ִ� ������ üũ
bool IsOddMonth(int& month_)
{
	for (auto& number : odd_month)
	{
		if (number == month_)
			return true;
	}
	return false;
}

// �� �Ǻ� �Լ�
MONTH Check_Month(Date& date_)
{
	if (IsOddMonth(date_.month))
		return ODD;

	else if (date_.month == 2)
	{
		if (IsLeapYear(date_.year))
			return LEAF;

		else
			return FEBRUARY;
	}

	else
		return EVEN;
}


// �Է� string parsing
void parsing_string(const std::string& s_, Date& date_)
{
	Date date;
	// parsing
	// year
	for (int i = 0; i < 4; i++)
	{
		date_.year += (s_.at(i) - '0') *  pow(10, 3 - i);
	}

	// month
	for (int i = 5; i < 7; i++)
	{
		date_.month += (s_.at(i) - '0') *  pow(10, 6 - i);
	}

	// day
	for (int i = 8; i < 10; i++)
	{
		date_.day += (s_.at(i) - '0') *  pow(10, 9 - i);
	}
}


// �⵵�� �� update, �̷��� ���
void Update_Plus(Date& date_)
{
	// 12�� ������ ���� ���
	if (date_.month == 12)
	{
		date_.year++;
		date_.month = 1;
	}

	// �� ��
	else
	{
		date_.month++;
	}

	date_.day = 1;
}

// �⵵�� �� update, ������ ���
void Update_Minus(Date& date_)
{
	// 1�� ������ ���� ���
	if (date_.month == 1)
	{
		date_.year--;  // �⵵ ����
		date_.month = 12; // ���⵵ 12���� ����
	}

	// �� ��
	else
	{
		date_.month--;
	}

	// ���� ��¥ ����
	switch (Check_Month(date_))
	{
	case ODD:
		date_.day = 31;
		break;

	case EVEN:
		date_.day = 30;
		break;

	case FEBRUARY:
		date_.day = 28;
		break;

	case LEAF:
		date_.day = 29;
		break;
	}
	
	
}


void Sub_days(int& days_, int subDays_)
{
	days_ -= subDays_; // ���� ��¥ ����
}

int main()
{
	// decla and init
	Date date;
	std::string input_;
	int days;

	date.year = 0;
	date.month = 0;
	date.day = 0;

	// input data
	cin >> input_ >> days;

	// parsing
	parsing_string(input_, date);
	
	// days �� �̷��� �� ���
	if (days > 0)
	{
		while (days > 0)
		{
			MONTH month = Check_Month(date); // �� ������ üũ
			int nIdentify;					 // ���� ��¥�� ���� �б⸦ ���� ���� �� �ܿ��Ͽ��� ������ ����

			// �޸��� �������� ������ �� ��¥��
			switch (month)
			{
			case ODD:
				nIdentify = 32 - date.day;
				break;

			case EVEN:
				nIdentify = 31 - date.day;
				break;
				
			case FEBRUARY:
				nIdentify = 29 - date.day;
				break;

			case LEAF:
				nIdentify = 30 - date.day;
				break;

			default:
				break;
			}

			// ��ǥ�� ���ϱ� ���� ���� ���� ���� �Ѵٸ�
			if (nIdentify <= days)
			{
				Sub_days(days, nIdentify); // �ܿ� �� ������ ����
				Update_Plus(date);                    // �� �ٲ���
			}

			// �̹� �� �ȿ� ��ǥ�� ������
			else
			{
				date.day += days;          // ���� �ٲ��� �ʰ� �ܿ����� ������
				Sub_days(days, nIdentify); // �ܿ����� ��� ����������
			}
		}
	}

	// ���ŷ� ���� ���
	else if (days < 0)
	{
		while (days < 0)
		{
			//cout << "days = " << days << "  " << "month, day = " << date.month << " " << date.day << endl;
			int nIdentify = date.day;

			// ��ǥ�� ���ϱ� ���� ���� ���� ���� �Ѵٸ�
			if (nIdentify <= -1 * days)
			{
				Sub_days(days, -1* nIdentify); // �ܿ� �� ������ ����
				Update_Minus(date);           // �� �ٲ���
			}

			// �̹� �� �ȿ� ��ǥ�� ������
			else
			{
				date.day += days;               // ���� �ٲ��� �ʰ� �ܿ����� ������
				Sub_days(days, -1 * nIdentify);  // �ܿ����� ��� ����������
			}
		}
	}

	cout << "Year :" << date.year << endl;
	cout << "Month :" << date.month << endl;
	cout << "Day :" << date.day << endl;

	return 0;
}