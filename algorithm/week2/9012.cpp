#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(void)
{
	stack<char> xxx;

	int countx;
	cin >> countx;

	for (int i = 0; i < countx; i++)
	{
		stack<char> xxx;
		string temp;
		cin >> temp;

		for (char x : temp)
		{
			if (x == '(') xxx.push(x);
			else
			{
				if (xxx.empty())
				{
					xxx.push(x);
					break;
				}
				else xxx.pop();
			}
		}

		if (xxx.empty())
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
	}
}