#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> templist;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int temp;
		cin >> temp;
		templist.push_back(temp);
	}

	for (auto xx : templist)
	{
		int count = 0;
		int count2 = 0;
		for (int i = 5; i <=xx; i*=5)
		{
			count2 += xx / i;
		}
		cout << count2 << "\n";
	}

}