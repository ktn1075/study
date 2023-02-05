#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

int main(void)
{
	
	vector<string> result;

	string temp;
	
	bool check = true;

	while (getline(cin, temp))
	{
		stack<char> s;
		if ("." == temp) break;
		check = true;
		for (char x : temp)
		{
			if ('(' == x) s.push('(');
			else if (')' == x)
			{
				if (!s.size() || s.top() != '(')
				{
					s.push(')');
					break;
				}
				s.pop();
			}

			if ('['==x) s.push('[');
			else if (']' == x)
			{
				if (!s.size() || s.top() != '[')
				{
					s.push(']');
					break;
				}
				s.pop();
			}
		}

		if (!s.size()) result.push_back("yes");
		else result.push_back("no");

	}
	
	for (auto x : result)
	{
		cout << x << "\n";
	}

}