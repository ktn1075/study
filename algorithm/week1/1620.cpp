/*
	���� : ���� �Է½� �׿� �ش�Ǵ� ���ڿ�, ���ڿ� �Է½� �ش� ��ȣ �� ��� 

	�ؼ� : ���ڿ� ���� �������� ���� ����� �Ѵ�.

	
	���� 



#include<vector>
#include<iostream>
#include<map>
#include<string>
#include<array>

using namespace std;
string _list2[100004];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k, m;
	cin >> n >> k;

	map<string, int> _list;

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;

		_list.insert({ temp,i + 1 });
		_list2[i + 1] = temp;
	}

// ==	stoi();


	for (int i = 0; i < k; i++)
	{
		string temp;
		cin >> temp;

		if (temp[0] >= 'A' && temp[0] <= 'Z')
		{
			cout << _list[temp]<<"\n";
		}
		else
		{
			cout << _list2[stoi(temp)] << "\n";
		}
	}

}
*/