/*

문제 :  펠린드롬인지 확인하기 - 앞으로 읽어도 뒤로 읽어도 똑같은 문자열 

입력 : 단어의 길이는 1보다 크거나 같고, 100보다 작거나 같으며, 알파벳 소문자로만 이루어져 있다.

해설 : 문자열을 리버스 해서 비교하거나, 문자열을 반으로 자르고 순차적으로 앞에서 부터 접근하고 뒤에서부터 접근하면서 처리가능


#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void)
{
	
	string t;
	cin >> t;

	int end = t.size()-1;
	int a = t.size() / 2;
	bool check = true;

	for (int i = 0; i < a; i++)
	{
		if (t[i] != t[end-i])
		{
			check = false;
			break;
		}
	}

	if (check == true)
		cout << 1;
	else
		cout << 0;

}

int main(void)
{
	string input_s;

	cin >> input_s;

	string temp = input_s;
	reverse(temp.begin(), temp.end());
	if (input_s == temp)
		cout << 1;
	else cout << 0;

}

*/