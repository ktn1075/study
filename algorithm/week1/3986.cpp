/*
#include<stack>
#include<iostream>
#include<string>

using namespace std;

bool checkS(string x1)
{
	stack<char> gggg;
	for (auto gg : x1)
	{
		if (gggg.empty())
		{
			gggg.push(gg);
			continue;
		}

		if (gggg.top() == gg)
		{
			gggg.pop();
		}
		else
		{
			gggg.push(gg);
		}
	}

	if (gggg.size() ==0)
	{
		return true;
	}
	return false;
}

int main(void)
{
	int x;
	string  gg;
	int count = 0;
	cin >> x;

	for (int i = 0; i < x; i++)
	{
		cin >> gg;

		if (checkS(gg)) count++;
	}

	cout << count;
}

*/