/*
문제 : 문자열을 ROT 13 문자열로 바꾸어 출력하시오

입력 : 첫째줄에 알파벳 대문자, 소문자, 공백, 숫자로만 이루어진 문자열 S 길이는 최대 100

해설 : 공백을 포함하여 문자열을 입력 받는다 - > getline(입력받을 IO, 문자열 저장 string 주소)

       아스키 코드값을 활용하여 +13 연산을 하여  각 아스키 코드의 범위 값 인경우 처리하도록 

#include<iostream>
#include<string>

using namespace std;


// 공백을 포함한 문자열을 입력받는다 
// getline(입력받을 IO, 문자열 저장 string 주소)
//
int main(void)
{
	string temp;
	
	int ka = 13;

	getline(cin,temp);

	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] >= 'a' && temp[i] <= 'z')
		{
			if (temp[i] + ka > 'z')
			{
				temp[i] = temp[i] + ka - 26;
				continue;
			}
			temp[i] = temp[i] + ka;
		}

		if (temp[i] >= 'A' && temp[i] <= 'Z')
		{
			if (temp[i] + ka > 'Z')
			{
				temp[i] = temp[i] + ka - 26;
				continue;
			}
			temp[i] = temp[i] + ka;
		}
	}

	cout << temp;
}

*/