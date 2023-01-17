/*
	문제 : 패턴 매칭 문제
	
	입력 :
	
	첫째 줄에 파일의 개수 N이 주어진다. (1 ≤ N ≤ 100)

    둘째 줄에는 패턴이 주어진다. 패턴은 알파벳 소문자와 별표(아스키값 42) 한 개로 이루어져 있다. 문자열의 길이는 100을 넘지 않으며, 별표는 문자열의 시작과 끝에 있지 않다.

    다음 N개 줄에는 파일 이름이 주어진다. 파일 이름은 알파벳 소문자로만 이루어져 있고, 길이는 100을 넘지 않는다.

	출력 : 일치시 DA 불일치시 NE

	해설 : 별표의 위치를 구하고 앞과 뒤를 나눠 문자열을 비교한다. 
	       Regex 사용하여 처리 
*/


#include<iostream>
#include<string>
#include <regex>
#include<algorithm>

using namespace std;


int main(void)
{
	int max = 0;
	cin >> max;

	cin.ignore();

	string temp;
	getline(cin,temp);

	auto location = temp.find('*');
	
	string pre = temp.substr(0, location);
	string end = temp.substr(location +1, temp.size()- location);

	for (int i = 0; i < max; i++)
	{
		
		string moon;
		cin >> moon;
		bool check = true;

		if ((pre + end).size() > moon.size())
			check = false;

		else
		{
			if (moon != pre + end)
			{
				string temp2 = moon.substr(0, pre.size());

				int location2 = moon.size() - end.size();
				string end2 = moon.substr(location2, end.size());

				if (pre != temp2 || end != end2)
					check = false;
			}
			else
			{
				check = true;
			}
		}
		if (check)
			cout << "DA" << "\n";
		else
			cout << "NE" << "\n";
	}

}