#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	int x = 666;
	int count = 0;
	int x1;
	cin >> x1;

	for (int i = 666; ; i++)
	{
		string temp = to_string(i);
		if (temp.find("666") != string::npos)
			count++;
		if (count == x1)
		{
			cout << temp;
			break;
		}
	}
}