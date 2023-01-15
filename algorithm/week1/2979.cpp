
/*
 문제 상근이는 트럭을 총 세 대 가지고 있다. 오늘은 트럭을 주차하는데 비용이 
 얼마나 필요한지 알아 보려고한다.

 상근이가 이용하는 주차장은 주차하는 트럭의 수에 따라서 주차요금을 할인해 준다.

 트럭을 한 대 주차할 때는 1분에 한 대당 A원을 내야 한다. 두 대를 주차할 때는
 1분에 한대당 B원, 세대를 주차할 때는 1분에 한 대당 C원을 내야 한다.

 A , B, C 가 주어지고, 상근이의 트럭이 주차장에 주차된 시간이 주어졌을때, 주차 
 요금으로 얼마를 내야 하는지 구하는 프로그램을 작성하시오.



 A 가 

 5, 3, 1 요금
 
 A는 1시에와서 6시에 출차
 B는 3시에와서 5시에 출차 
 C는 2시에와서 8시에 출차 

 3 * 100 ?
A B C
1 1 1  = C원               1 
0 1 1  = B원               1 
1 0 0  = A원               1  
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
