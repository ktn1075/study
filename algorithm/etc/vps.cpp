
// °ýÈ£¹®Á¦
/*
#include<string>
#include<stack>
#include<iostream>

using namespace std;

int main(void)
{
	stack<int> s;
	string temp;

	cin >> temp;

	for (char c : temp)
	{
		if (c == '(') s.push(c);

		if (c == ')')
		{
			if (!s.size())
			{
				s.push(c);
				break;
			}
			s.pop();
		}
	}

if (!s.size())
{
	cout << "YES";
}
else
{
	cout << "NO";
}
}

*/