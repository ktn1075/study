#include<iostream>

using namespace std;

int main(void)
{

	

	int n, m, countx;
	int location = 1;
	int ret = 0;
	cin >> n >> m >> countx;

	for (int i = 0; i < countx; i++)
	{
		int temp;
		cin >> temp;

		if (location == temp)
		{
			ret++;
			continue;
		}

		while (true)
		{
			if (location < temp)
			{
				if (location <= temp && temp <= location + m - 1) break;				
				location++;
			}
			else
			{
				if (location -m+1 <= temp && temp <= location) break;
				location--;
			}
			ret++;
		}
	}
	
	cout << ret;
}