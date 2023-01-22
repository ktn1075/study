/*
#include<iostream>
#include<string>
#include<vector>

using namespace std;


int k;
int count2 = 0;
int x[100010];
vector<int> x1;
int o;

void combi(int start)
{
	if (x1.size() == 2)
	{
		int sum = 0;
		for (auto g : x1) sum += g;
		if (sum == k)
		{
			count2++;
		}
		return;
	}

	for (int i = start+1; i <=o; i++)
	{
		x1.push_back(x[i]);
		combi(i);
		x1.pop_back();
	}
}

int main(void)
{

	cin >> o;
	cin >> k;

	for (int i = 1; i <=o ; i++)
	{
		int temp;
		cin >> temp;
		x[i] = temp;
	}

	combi(0);
	cout << count2 << "\n";
}*/