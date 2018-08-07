#include <iostream>
#include <vector>
#include <deque>
#include <math.h>
using namespace std;


typedef struct ColorCost
{
	int red;
	int green;
	int blue;
}ColorCost;

enum RGB { RED, GREEN, BLUE };

typedef struct DPItem
{
	int total_sum;
	RGB beforeColor;
}DPItem;


// g variable
vector<ColorCost> cost; // Each house's drawing color cost info
int N; // the number of house
deque<DPItem> dpVec; // Container which saves DP func's result value.


// ColorCost cc_ : next house's color cost data
void bottomUpDp(ColorCost cc_)
{
	pair <int, int> R_end; //GR BR
	pair <int, int> G_end; //RG BG
	pair <int, int> B_end; //RB GB
	
	DPItem Red, Green, Blue;

	for (int i = 0; i < 3; i++)
	{
		if (dpVec.front().beforeColor == RED)
		{
			G_end.first = dpVec[0].total_sum + cc_.green; // RG
			B_end.first = dpVec[0].total_sum + cc_.blue;  // RB
		}

		else if (dpVec.front().beforeColor == GREEN)
		{
			R_end.first = dpVec[0].total_sum + cc_.red;		// GR
			B_end.second = dpVec[0].total_sum + cc_.blue;	// GB 
		}	

		else if (dpVec.front().beforeColor == BLUE)
		{
			G_end.second = dpVec[0].total_sum + cc_.green; // BG
			R_end.second = dpVec[0].total_sum + cc_.red;    // BR
		}

		dpVec.pop_front();
	}

	// Color Init
	Red.beforeColor = RED;
	Blue.beforeColor = BLUE;
	Green.beforeColor = GREEN;

	// Data determine with comparison
	Red.total_sum = R_end.first < R_end.second ? R_end.first : R_end.second;
	Green.total_sum = G_end.first < G_end.second ? G_end.first : G_end.second;
	Blue.total_sum = B_end.first < B_end.second ? B_end.first : B_end.second;
	
	// Input data to deque
	dpVec.push_back(Red);
	dpVec.push_back(Green);
	dpVec.push_back(Blue);

}

int main()
{
	cin >> N; // N <= 1000

	// Container Init
	cost.resize(N);
	dpVec.resize(3);
	//cout << dpVec.size() << endl;

	// Input cost data
	for (int i = 0; i < N; i++) 
		cin >> cost[i].red >> cost[i].green >> cost[i].blue;

	// First Home Init
	dpVec[0].beforeColor = RED;
	dpVec[0].total_sum = cost[0].red;

	dpVec[1].beforeColor = GREEN;
	dpVec[1].total_sum = cost[0].green;

	dpVec[2].beforeColor = BLUE;
	dpVec[2].total_sum = cost[0].blue;

	// DP
	for (int j = 1; j < N; j++)
		bottomUpDp(cost[j]);

	/*for (int k = 0; k < 3 * pow(2, (N - 1)); k++)
		cout << dpVec[k].total_sum << " ";
	cout << endl;*/

	int result = dpVec[0].total_sum;

	for (int k = 1; k < dpVec.size(); k++)
	{
		if (result > dpVec[k].total_sum)
			result = dpVec[k].total_sum;
	}

	cout << result << endl;
	
	return 0;
}


