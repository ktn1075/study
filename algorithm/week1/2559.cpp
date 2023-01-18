#include<iostream>
#include<vector>


using namespace std;
int main(void)
{

	int maxCount, rotation;
	int tempList[100200] = { 0 };
;	int max = -991199;
	cin >> maxCount >> rotation;

	for (int i = 1; i <=maxCount; i++)
	{
		int temp = 0;
		cin >> temp;
		tempList[i] = tempList[i - 1] + temp;
	}
	for (int j = rotation; j <=maxCount; j++)
	{
		int x = tempList[j] - tempList[j-rotation];
		if (max < x)
		{
			max = x;
		}
	}
	cout << max;
}