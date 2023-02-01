/*
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(string& a, string& b)
{
	if (a.size() == b.size())
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] < b[i]) return true;
			if (a[i] > b[i]) return false;
		}
	}
	return  a.size() < b.size();
}


// »ó
int main(void)
{

	vector<string> resulut;

	int  n;
	cin >> n;

	for (long i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		string re;
		for (char c : temp)
		{
			if ('0' <= c && c <= '9') 
			{ 
				if (re.size() && re[0] == '0')
				{
					if (c == '0') continue;
					re.clear();
				}
				re += c;
			}
			else
			{
				if (re.size() != 0)
				{
					resulut.push_back(re);
					re.clear();
				}
			}
		}
		if (re.size())	resulut.push_back(re);
	}

	sort(resulut.begin(), resulut.end(), comp);

	for (auto  x : resulut)
	{
		cout << x << "\n";
	}
}
*/