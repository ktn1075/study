
/*
 ���� ����̴� Ʈ���� �� �� �� ������ �ִ�. ������ Ʈ���� �����ϴµ� ����� 
 �󸶳� �ʿ����� �˾� �������Ѵ�.

 ����̰� �̿��ϴ� �������� �����ϴ� Ʈ���� ���� ���� ��������� ������ �ش�.

 Ʈ���� �� �� ������ ���� 1�п� �� ��� A���� ���� �Ѵ�. �� �븦 ������ ����
 1�п� �Ѵ�� B��, ���븦 ������ ���� 1�п� �� ��� C���� ���� �Ѵ�.

 A , B, C �� �־�����, ������� Ʈ���� �����忡 ������ �ð��� �־�������, ���� 
 ������� �󸶸� ���� �ϴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.



 A �� 

 5, 3, 1 ���
 
 A�� 1�ÿ��ͼ� 6�ÿ� ����
 B�� 3�ÿ��ͼ� 5�ÿ� ���� 
 C�� 2�ÿ��ͼ� 8�ÿ� ���� 

 3 * 100 ?
A B C
1 1 1  = C��               1 
0 1 1  = B��               1 
1 0 0  = A��               1  
0                          1
0                          1
                          1
 */


#include<iostream>
#include<string>


using namespace std;


int result[3][100];
int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;
	int sum = 0;

	int x, y;
	cin >> x >> y;

	for (int i = x - 1; x < y-2; x++)
	{
		result[0][x] = 1;
	}
	cin >> x >> y;

	for (int i = x - 1; x < y - 2; x++)
	{
		result[1][x] = 1;
	}

	cin >> x >> y;
	for (int i = x - 1; x < y - 2; x++)
	{
		result[2][x] = 1;
	}


	for (int i = 0; i < 100; i++)
	{
		int temp = 0;

		for (int j = 0; j < 3; j++)
		{
			cout << result[j][i];
			temp += result[j][i];
		}


		switch (temp)
		{
		case 1:
			sum += a * 1;
			break;
		case 2: 
			sum += b * 2;
			break;
		case 3:
			sum += c * 3;
			break;
		}
	}

	cout << sum << "\n";
}
