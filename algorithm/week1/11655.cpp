/*
���� : ���ڿ��� ROT 13 ���ڿ��� �ٲپ� ����Ͻÿ�

�Է� : ù°�ٿ� ���ĺ� �빮��, �ҹ���, ����, ���ڷθ� �̷���� ���ڿ� S ���̴� �ִ� 100

�ؼ� : ������ �����Ͽ� ���ڿ��� �Է� �޴´� - > getline(�Է¹��� IO, ���ڿ� ���� string �ּ�)

       �ƽ�Ű �ڵ尪�� Ȱ���Ͽ� +13 ������ �Ͽ�  �� �ƽ�Ű �ڵ��� ���� �� �ΰ�� ó���ϵ��� 

#include<iostream>
#include<string>

using namespace std;


// ������ ������ ���ڿ��� �Է¹޴´� 
// getline(�Է¹��� IO, ���ڿ� ���� string �ּ�)
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