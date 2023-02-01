#include<iostream>


using namespace std;

int a[105][105] = {-1};

int h, w;

int main(void)
{
	cin >> h >> w;

	for (int i = 0; i < h; i++)
	{
		string temp;
		cin >> temp;

		int count = -1;
		for (int j = 0; j < temp.size(); j++)
		{
			if (temp[j] == 'c')
			{
				if (count != 0) count = 0;
			}
			else
			{
				if (count != -1) count++;
			}

			a[i][j] = count;
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}