/*

���� :  �縰������� Ȯ���ϱ� - ������ �о �ڷ� �о �Ȱ��� ���ڿ� 

�Է� : �ܾ��� ���̴� 1���� ũ�ų� ����, 100���� �۰ų� ������, ���ĺ� �ҹ��ڷθ� �̷���� �ִ�.

�ؼ� : ���ڿ��� ������ �ؼ� ���ϰų�, ���ڿ��� ������ �ڸ��� ���������� �տ��� ���� �����ϰ� �ڿ������� �����ϸ鼭 ó������


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