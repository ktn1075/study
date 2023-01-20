/*
	문제 : 숫자 입력시 그에 해당되는 문자열, 문자열 입력시 해당 번호 값 출력 

	해설 : 문자열 인지 숫자인지 구분 지어야 한다.

	
	문자 



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