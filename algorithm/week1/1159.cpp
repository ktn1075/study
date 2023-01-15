/*

성의 첫 글자가 같은 멤버 5명을 출력하는 문제이다.

해설 : 알파벳을 저장 할 수 있는 배열 선언 후 해 아스키 코드 값 을 활용해 5명 이상인 알파벳을 찾아낸다. 



#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


int main(void)
{

	int count[26] = { 0 };

	int max;

	cin >> max;

	bool check = false;

	for (int i = 0; i < max; i++)
	{
		string inputS;
		cin >> inputS;
		count[inputS[0] - 'a']++;
	}	

	for (int i = 0; i < 26; i++)
	{
		if (count[i] >= 5)
		{
			cout << (char)(i + 'a');
			check = true;
		}
	}

	if (check == false)
	{
		cout << "PREDAJA";
	}

}

*/