/*
#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	
	while (true)
	{
		int countx = 0, countx2 = 0, countx3 = 0;
		char preChar = ' ';
		bool check = true;
		string temp;
		cin >> temp;

		if (temp == "end") break;

		for (auto c : temp)
		{
			if (preChar == c)
			{
				if (c == 'e' || c == 'o')
				{
				}
				else
				{
					check = false;
					break;
				}
			}
			switch (c)
			{
			case 'a':
				countx3 = 1;
				countx++;
				countx2 = 0;
				break;
			case 'e':
				countx3 = 1;
				countx++;
				countx2 = 0;
				break;
			case 'i':
				countx3 = 1;
				countx++;
				countx2 = 0;
				break;
			case 'o':
				countx3 = 1;
				countx++;
				countx2 = 0;
				break;
			case 'u':
				countx3 = 1;
				countx++;
				countx2 = 0;
				break;
			default:
				countx2++;
				countx = 0;
				break;
			}

			if (countx >= 3 || countx2 >=3) 
			{
				check = false;
				break;
			}

			preChar = c;
		}

		string result = "<" + temp + ">";
		
		if (check && countx3) cout << result << " is acceptable."<<"\n";
		else cout << result << " is not acceptable."<<"\n";
	}

}

*/