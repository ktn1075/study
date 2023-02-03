#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>

using namespace std;
int prevx, asum, bsum;

void go(int& sum, int s)
{
	sum += s - prevx;
}

string printx(int sum)
{
	// sum은 초이므로

	string re;
	int m = sum / 60;
	sum = sum % 60;
	if (!(m / 10)) re += "0";
	re+=to_string(m) + ":";
	if (!(sum / 10)) re += "0";
	re += to_string(sum);
	
	return re;
}


int main(void)
{
	int n;
	cin >> n;
	int wincount1 = 0;
	int wincount2 = 0;

	for (int i = 0; i < n; i++)
	{
		int m, s, team;
		scanf("%d %d:%d", &team, &m, &s);
		s += m * 60;
		if (wincount1 > wincount2) go(asum, s);
		else if (wincount2 > wincount1) go(bsum, s);
		team == 1 ? wincount1++ : wincount2++;
		prevx = s;
	}

	if (wincount1 > wincount2) go(asum, 48 * 60);
	else if (wincount2 > wincount1) go(bsum, 48 * 60);

	cout << printx(asum) << "\n";
	cout << printx(bsum) << "\n";
}
