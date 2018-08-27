#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// Queue item. It contains wine info.
typedef struct Wine{
	vector<int> vWineIndex;
	int nTotalWineAmount;
}Wine;

int n;	// Input. The number of wine glasses. 
vector<int> vWineVol; // Volume which wine glass has.
deque<Wine> qDpContainer; // It contains DP items. It used for dp func. 


void Wine_DP()
{
	while (qDpContainer.size() != 1)
	{
		// No more can't attach other wines to vector.
		if (qDpContainer.front().vWineIndex.back() >= n)
		{
			bool bIsBigger = false;

			// Check bigger wine total volumes in deque. 
			for (int i = 1; i < qDpContainer.size(); i++)
			{
				if (qDpContainer.front().nTotalWineAmount < qDpContainer[i].nTotalWineAmount)
				{
					bIsBigger = true;
					break;
				}
			}

			// If no, than push to deque again.
			if (!bIsBigger)
			{
				Wine wTemp = qDpContainer.front();
				qDpContainer.push_back(wTemp);
			}
		}

		else
		{
			// Wine structure's last index's number
			int nLastNum = qDpContainer.front().vWineIndex.back() + 1;

			for (int i = nLastNum; i <= n; i++)
			{
				// If new number is put consecutively with past two ones, 
				// skip creating a new structure and pusing the item.
				if (nLastNum != 1 && nLastNum != 2)
				{

				}

				if (qDpContainer.front().vWineIndex[nLastNum - 2] + 1 == qDpContainer.front().vWineIndex[nLastNum - 1] &&
					qDpContainer.front().vWineIndex[nLastNum - 1] + 1 == qDpContainer.front().vWineIndex[nLastNum])
					continue;
		
				else
				{
					Wine wTemp = qDpContainer.front();
					wTemp.vWineIndex.push_back(i);
					wTemp.nTotalWineAmount += vWineVol[i];

					qDpContainer.push_back(wTemp);
				}
			}
		}

		qDpContainer.pop_front();
	}

	// Print Maximum number
	cout << qDpContainer.front().nTotalWineAmount << endl;
}

int main()
{
	cin >> n;
	vWineVol.resize(1, 0); // Ignore Index 0
	
	// Input
	for (int i = 1; i<= n; i++)
	{
		int nTemp; // Wine Volume
		cin >> nTemp;
		vWineVol.push_back(nTemp);
		
		Wine wTemp;
		wTemp.vWineIndex.resize(1, 0);
		wTemp.vWineIndex.push_back(i);
		wTemp.nTotalWineAmount = nTemp;
		qDpContainer.push_back(wTemp);
	}

	Wine_DP();

	return 0;
}