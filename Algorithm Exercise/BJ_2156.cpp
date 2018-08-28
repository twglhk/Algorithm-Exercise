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
		// Can't attach other wines to vector.
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
			int nLastNum = qDpContainer.front().vWineIndex.back();
			vector<int>::iterator vIter = qDpContainer.front().vWineIndex.end()-1;

			for (int i = nLastNum+1; i <= n; i++)
			{
				// If new number is put consecutively with past two ones, 
				// skip creating a new structure and pusing the item.
				if (qDpContainer.front().vWineIndex.size() >= 2)
				{
					if (*(vIter - 1) + 1 == *vIter && *vIter + 1 == i)
					{
						if (i == n)
						{
							Wine wTemp = qDpContainer.front();
							wTemp.vWineIndex.push_back(i+1);
							qDpContainer.push_back(wTemp);
							break;
						}
							
						else
							continue;
					}
				}
				
				// Memorization
				Wine wTemp = qDpContainer.front();
				wTemp.vWineIndex.push_back(i);
				wTemp.nTotalWineAmount += vWineVol[i];

				qDpContainer.push_back(wTemp);
			}
		}

		qDpContainer.pop_front();
	}

	// Print Maximum number
	/*for (int i = 0; i < qDpContainer.front().vWineIndex.size(); i++)
		cout << qDpContainer.front().vWineIndex[i] << " ";
	cout << endl;*/

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
		wTemp.vWineIndex.push_back(i);
		wTemp.nTotalWineAmount = nTemp;
		qDpContainer.push_back(wTemp);
	}

	/*cout << "WINE VOL" << endl;
	for (int i = 0; i < vWineVol.size(); i++)
	{
		cout << vWineVol[i] << " ";
	}
	cout << endl;
	cout << "------------" << endl*/;

	Wine_DP();

	return 0;
}