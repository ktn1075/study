/*

문제 :  알파벳 소문자로만 이루어진 단어 S가  주어진다. 각 알파벳이 단어에 몇개가 포함되어 있는지
        구하는 프로그램을 작성하시오 .

입력 : 첫째 줄에 단어 S가 주어진다. 단어의 길이는 100을 넘지 않으며, 알파벳 소문자로만 이루어져 있다.

해설 : 문자는 아스키코드로 처리 된다고 생각하고, 배열을 선언 한후 처리 한다.


#include<iostream>
#include<string>


using namespace std;


int result[26];
int main(void)
{
	string a;
	cin >> a;

	for (char t : a)
	{
		result[t - 'a']++;
	}
	
	for (int i = 0; i < 26; i++)
	{
		cout << result[i] << " ";
	}
}

*/