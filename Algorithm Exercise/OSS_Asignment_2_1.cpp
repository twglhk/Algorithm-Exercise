#include <iostream>
#include <string>
#include <math.h>
#include <array>

using namespace std;

std::array<int, 7> odd_month = { 1,3,5,7,8,10,12 }; // 31일까지 있는 달
enum MONTH { ODD, EVEN, FEBRUARY , LEAF }; // 31일달, 30일달, 2월, 윤달

typedef struct Date
{
	int year, month, day;
}Date;


// 윤달 체크 함수
bool IsLeapYear(int& year_)
{
	if (year_ % 4 == 0)
		return true;

	else
		return false;
}


// 31일까지 있는 달인지 체크
bool IsOddMonth(int& month_)
{
	for (auto& number : odd_month)
	{
		if (number == month_)
			return true;
	}
	return false;
}

// 월 판별 함수
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


// 입력 string parsing
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


// 년도와 월 update, 미래의 경우
void Update_Plus(Date& date_)
{
	// 12월 연산이 끝난 경우
	if (date_.month == 12)
	{
		date_.year++;
		date_.month = 1;
	}

	// 그 외
	else
	{
		date_.month++;
	}

	date_.day = 1;
}

// 년도와 월 update, 과거의 경우
void Update_Minus(Date& date_)
{
	// 1월 연산이 끝난 경우
	if (date_.month == 1)
	{
		date_.year--;  // 년도 감소
		date_.month = 12; // 전년도 12월로 변경
	}

	// 그 외
	else
	{
		date_.month--;
	}

	// 말일 날짜 저장
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
	days_ -= subDays_; // 남은 날짜 차감
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
	
	// days 가 미래로 갈 경우
	if (days > 0)
	{
		while (days > 0)
		{
			MONTH month = Check_Month(date); // 몇 월인지 체크
			int nIdentify;					 // 남은 날짜와 비교해 분기를 만들 변수 및 잔여일에서 빠지는 숫자

			// 달마다 정해지는 앞으로 갈 날짜들
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

			// 목표를 구하기 위해 다음 달을 가야 한다면
			if (nIdentify <= days)
			{
				Sub_days(days, nIdentify); // 잔여 일 수에서 차감
				Update_Plus(date);                    // 달 바꿔줌
			}

			// 이번 달 안에 목표가 있으면
			else
			{
				date.day += days;          // 달을 바꾸지 않고 잔여일을 더해줌
				Sub_days(days, nIdentify); // 잔여일을 모두 소진시켜줌
			}
		}
	}

	// 과거로 가는 경우
	else if (days < 0)
	{
		while (days < 0)
		{
			//cout << "days = " << days << "  " << "month, day = " << date.month << " " << date.day << endl;
			int nIdentify = date.day;

			// 목표를 구하기 위해 이전 달을 가야 한다면
			if (nIdentify <= -1 * days)
			{
				Sub_days(days, -1* nIdentify); // 잔여 일 수에서 차감
				Update_Minus(date);           // 달 바꿔줌
			}

			// 이번 달 안에 목표가 있으면
			else
			{
				date.day += days;               // 달을 바꾸지 않고 잔여일을 더해줌
				Sub_days(days, -1 * nIdentify);  // 잔여일을 모두 소진시켜줌
			}
		}
	}

	cout << "Year :" << date.year << endl;
	cout << "Month :" << date.month << endl;
	cout << "Day :" << date.day << endl;

	return 0;
}