#include "CustomAlgol.h"
using namespace std;

int g_nLength; // length of Original message
int g_nOneCount; // the number of 1's counts
int g_nPosibility = 0; // posibility of repairable original bit pattern
std::vector<string> g_sHistory;
std::string g_sCompressedData; // Compressed binary number

// Count the number of '1' in string 
int CountBit(const std::string& str)
{
	int nCount = 0;

	FOR(i, str.size())
	{
		if (str[i] == '1')
			nCount++;
	}
	return nCount;
}

// Calculate sequence of 1 bit in original binary number from input string
// ex) 1100 => 12 =>111111111111
std::string GetBinaryNum(const std::string& str)
{
	int nDecimal = 0;
	std::string strTemp;
	
	FOR(i, str.size())
	{
		if (str[i] - '0' == 1)
		{
			nDecimal += pow(2, str.size() - i - 1);
		}	
	}

	FOR(i, nDecimal)
	{
		strTemp += '1';
	}	
	return strTemp;
}

std::string TripleDivision(const std::string& str ,int start, int& end)
{
	// Parsing compressed data
	std::string strFront, strMid, strBack, strFull;

	// Front parsing
	strFront = str.substr(0, start);

	// Mid parsing
	strMid = str.substr(start, end-start);
	if (strMid[0] != '0') // if parsing string starts from '1'
		strMid = GetBinaryNum(strMid); // Get sequence of '1'

	// Back parsing
	strBack = str.substr(end , str.size()-end);

	end = start + strMid.size(); // end uptade

	strFull = strFront + strMid + strBack; // merge

	return strFull;
}

std::string DecToBin(std::string str)
{
	std::string sCompress = "";
	std::string sTemp = "";
	std::string sBinary = "";
	int nTemp;
	int nCount = 0;

	FOR(i, str.size())
	{
		if (str[i] == '1')
		{
			nCount++;
			sTemp += '1';

			// last index
			if (i == str.size() - 1)
			{
				if (nCount < 3)
				{
					sCompress += sTemp;
				}

				else
				{
					nTemp = nCount;
					while (true)
					{
						sBinary += to_string(nTemp % 2);
						nTemp /= 2;

						if (nTemp == 1)
						{
							sBinary += '1';
							break;
						}
					}

					for (int j = sBinary.size() - 1; j >= 0; j--)
						sCompress += sBinary[j];
				}
			}
		}

		else
		{
			if (nCount < 3)
			{
				sTemp += "0";
				sCompress += sTemp;
			}

			else
			{
				nTemp = nCount;
				while (true)
				{
					sBinary += to_string(nTemp % 2);
					nTemp /= 2;

					if (nTemp == 1)
					{
						sBinary += '1';
						break;
					}
				}

				for (int j = sBinary.size() - 1; j >= 0; j--)
					sCompress += sBinary[j];

				sCompress += '0';
			}

			sTemp = "";
			sBinary = "";
			nTemp = 0;
			nCount = 0;
		}

	}

	return sCompress;
}

void RecursiveFunc(std::string string, int start, int end)
{
	// Parsing string
	std::string str = TripleDivision(string, start, end);
	
	// Size comparing with original one's size
	if (str.size() == g_nLength)
	{
		if (CountBit(str) == g_nOneCount)
		{
			if (DecToBin(str) == g_sCompressedData)
			{
				FOR(i, g_sHistory.size())
				{
					if (g_sHistory[i] == str)
						return;
				}

				g_sHistory.push_back(str);
				g_nPosibility++;  // Increasae the number of posiible original one.
			}
			else
				return;		
		}
	}

	// Not same
	else
	{
		// It needs to parisng until it reaches to same bit length of original one.  
		if (str.size() < g_nLength)
		{
			// Minimum size
			if (end + 3 <= str.size())
			{
				// Update Range
				start = end;
			
				for (int i = str.size(); i > 2; i--)
					for (int j = start, tempEnd = i; tempEnd <= str.size() && tempEnd - start > 2; j++, tempEnd++)
						RecursiveFunc(str, j, tempEnd);
			}
		}
	}
}

int main()
{
	// input
	cin >> g_nLength >> g_nOneCount;
	cin.ignore();
	getline(cin, g_sCompressedData); 
	
	for (int i = g_sCompressedData.size(); i > 2; i--)
	{
		// Parsing range
		int start, end;
		start = 0;
		end = i;

		for (int j = start; end <= g_sCompressedData.size() && end - j > 2; j++, end++)
		{
			RecursiveFunc(g_sCompressedData, j, end);
			//cout << "Main Loop called" << endl;
		}
	}

	
	if (g_nPosibility == 0)
		cout << "NO" << endl;

	else if (g_nPosibility == 1)
		cout << "YES" << endl;

	else
		cout << "NOT UNIQUE" << endl;

	return 0;
}