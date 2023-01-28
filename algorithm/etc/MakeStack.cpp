/*#include<iostream>

using namespace std;
int main(void)
{
	int n, m, top = 0;
	cin >> n >> m;

	int *mstack = new int[n];

	for (int i = 0; i <m; i++)
	{
		int order, value;
		cin >> order;
		switch (order)
		{

		case 1:
			cin >> value;
			if (top >= n)
				cout << "Overflow" << "\n";
			else
			{
				mstack[top] = value;
				top++;
			}
			break;

		case 2:
			if (top == 0) cout << "Underflow" << "\n";
			else top--;
			break;

		case 3:
			if (top == 0) cout << "NULL" << "\n";
			else cout << mstack[top-1] << "\n";
			break;

		default:
			break;
		}
	}
 }
 */
