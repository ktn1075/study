#include<iostream>

using namespace std;

int main(void)
{
	int n, m, countx;
	int location = 1;
	int ret = 0 , si = 0;
	cin >> n >> m >> countx;

	for (int i = 0; i < countx; i++)
	{
		si = location + m - 1;
		int temp;
		cin >> temp;

		if (temp >= location && temp <= si) continue;

		else
		{
			if (temp < location)
			{
				ret += (location - temp);
				location = temp;
			}
			else {
				location += (temp - si);
				ret += (temp - si);
			}
		}
	}
	
	cout << ret;
}