#include<iostream>
#include<string>
#include<queue>
#include<vector>

using namespace std;

int main(void)
{
	string temp;
	vector<string> result;

	while(getline(cin,temp))
	{ 
		// 종료조건
		if (temp == ".")
		{
			cout << "YES";
			break;
		}

		queue<char> q1;
		queue<char> q2;
		for (auto x : temp)
		{
			if (x == '(')
			{
				q1.push('(');
			}
			else if (x == ')')
			{
				if (!q1.size())
				{

					break;
				}
			}
			if (x == '[')
			{

			}
			else if (x == ']')
			{
				if (!q2.size())
				{

					break;
				}
			}

		}
	}
}