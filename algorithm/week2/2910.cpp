/*
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(pair<int,pair<int, int>> &a ,pair<int, pair<int, int>>&b)
{
	if (a.second.first == b.second.first)
		return a.second.second < b.second.second;

	return a.second.first > b.second.first;
}

bool cmp2(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b)
{
	return a.second.second < b.second.second;
}


int main(void)
{
	map<int, pair<int, int>> s;

	int n, c;

	cin >> n >> c;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		if (!s.count(temp))
		{
			s.insert({ temp, make_pair(1,i)});
		}
		else
		{
			s[temp].first += 1;
		}
	}

	vector<pair<int, pair<int, int>>> v(s.begin(),s.end());

	sort(v.begin(),v.end(),cmp);


	for (auto x : v)
	{
		for (int i = 0; i < x.second.first; i++)
		{
			cout << x.first << " ";
		}
	}

}
*/