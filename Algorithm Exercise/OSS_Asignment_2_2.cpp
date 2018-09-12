#include <iostream>
#include <vector>

using namespace std;

// Area structure
typedef struct Area
{
	std::pair<int, int> row;
	std::pair<int, int> col;
}Area;

std::vector<std::vector<int>> g_Matrix;
int g_N; // Matrix size
int g_Max = 0; // Max value in subset of matrix
Area g_Area, g_AnswerArea;

int SumMatrix(const Area& area_)
{
	int temp = 0;

	for (int i = area_.row.first; i <= area_.row.second; i++)
	{
		for (int j = area_.col.first; j <= area_.col.second; j++)
		{
			temp += g_Matrix[i][j];
		}
	}
	return temp;
}

void FindMaxSubset(Area& area_)
{

	// Max finding
	int temp = SumMatrix(area_);

	if (g_Max < temp)
	{
		g_AnswerArea = area_;
		g_Max = temp;
	}

	// Remains only 1X1 matrix subset
	if (area_.row.first == area_.row.second && area_.col.first == area_.col.second)
	{
		return;
	}

	else
	{
		// Upside cutting
		if (area_.row.first != area_.row.second)
			FindMaxSubset(Area{ std::pair<int, int>(area_.row.first, area_.row.second - 1), area_.col });

		// LeftSide cutting
		if (area_.col.first != area_.col.second)
			FindMaxSubset(Area{ area_.row , std::pair<int, int>(area_.col.first, area_.col.second - 1) });

		// BottomSide cutting
		if (area_.row.first != area_.row.second)
			FindMaxSubset(Area{ std::pair<int, int>(area_.row.first + 1, area_.row.second), area_.col });

		// RightSide cutting
		if (area_.col.first != area_.col.second)
			FindMaxSubset(Area{ area_.row , std::pair<int, int>(area_.col.first + 1, area_.col.second) });
	}
}


int main()
{
	// Input and Init
	cin >> g_N;
	g_Matrix.resize(g_N);

	// Origin matrix area
	g_Area.row.first = g_Area.col.first = 0;
	g_Area.row.second = g_Area.col.second = g_N - 1;

	// Default answer init
	g_AnswerArea = g_Area;


	for (int i = 0; i < g_N; i++)
	{
		g_Matrix[i].resize(g_N);

		for (int j = 0; j < g_N; j++)
		{
			cin >> g_Matrix[i][j];
			g_Max += g_Matrix[i][j]; // Total sum of elements in origin matrix
		}
	}

	FindMaxSubset(g_Area); // Devie and Conquer

	cout << "Max = " << g_Max << endl;
	cout << "Area " << endl;
	cout << "ROW = ( " << g_AnswerArea.row.first << " - " << g_AnswerArea.row.second << " )" << endl;
	cout << "COL = ( " << g_AnswerArea.col.first << " - " << g_AnswerArea.col.second << " )" << endl;

	return 0;
}