/*

���� ù ���ڰ� ���� ��� 5���� ����ϴ� �����̴�.

�ؼ� : ���ĺ��� ���� �� �� �ִ� �迭 ���� �� �� �ƽ�Ű �ڵ� �� �� Ȱ���� 5�� �̻��� ���ĺ��� ã�Ƴ���. 



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