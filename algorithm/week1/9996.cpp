/*
	���� : ���� ��Ī ����
	
	�Է� :
	
	ù° �ٿ� ������ ���� N�� �־�����. (1 �� N �� 100)

    ��° �ٿ��� ������ �־�����. ������ ���ĺ� �ҹ��ڿ� ��ǥ(�ƽ�Ű�� 42) �� ���� �̷���� �ִ�. ���ڿ��� ���̴� 100�� ���� ������, ��ǥ�� ���ڿ��� ���۰� ���� ���� �ʴ�.

    ���� N�� �ٿ��� ���� �̸��� �־�����. ���� �̸��� ���ĺ� �ҹ��ڷθ� �̷���� �ְ�, ���̴� 100�� ���� �ʴ´�.

	��� : ��ġ�� DA ����ġ�� NE

	�ؼ� : ��ǥ�� ��ġ�� ���ϰ� �հ� �ڸ� ���� ���ڿ��� ���Ѵ�. 
	       Regex ����Ͽ� ó�� 
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