#include <iostream>
#include <string>
#include <vector>
#include "CustomAlgol.h"

using namespace std;

/*
11111111001001111111111111110011 ดย
1000    0010011110011 

*/

int main()
{
	DEBUG_ON;
	std::string str = "11111111001001111111111111110011";
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

				for (int j = sBinary.size()-1; j >= 0; j--)
					sCompress += sBinary[j];

				sCompress += '0';
			}

			sTemp.clear();
			sBinary.clear();
			nTemp = 0;
			nCount = 0;

		}

		DEBUG_VALUE("Binary", sBinary);
		DEBUG_VALUE("int Count", nCount);
		DEBUG_VALUE("string Temp", sTemp);
		DEBUG_VALUE("string Compress", sCompress);
		ENTER;
	}

	DEBUG_VALUE("COMPRESSE string", sCompress);

	return 0;
}