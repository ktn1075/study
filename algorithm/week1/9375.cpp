#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


map<string, int> _list;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	int testcase = 0;
	cin >> testcase;


	for (int i = 0; i < testcase; i++)
	{
		_list.clear();
		int temp = 0;
		cin >> temp;

		for (int j = 0; j < temp; j++)
		{
			string temp2;
			cin >> temp2;
			cin >> temp2;
			
			//getline(cin, temp2);

			if (_list.count(temp2))
			{
				_list[temp2] += 1;
			}
			else
			{
				_list.insert({ temp2,1});
			}
		}
		int sum = 1;
		for (auto t : _list)
		{
			sum = (t.second + 1) * sum;
		}

		cout << sum - 1 << "\n";
	}
}