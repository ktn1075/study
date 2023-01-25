/*
#include<queue>
#include <iostream>
#include <tuple>
#include<cstdio>

using namespace std;

int a[105][105] = { 0 };
int visit[105][105] = { 0 };
int n;
int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };
int res = 1;

void dfs(int y, int x, int dj)
{
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (!visit[ny][nx] && a[ny][nx] > dj) dfs(ny, nx, dj);
	}
}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			a[i][j] = temp;
		}
	}

	for (int dj = 1; dj < 101; dj++)
	{

		fill(&visit[0][0], &visit[0][0] + 105 * 105, 0);
		
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visit[i][j] && a[i][j] > dj)
				{
					dfs(i, j,dj);
					cnt++;
				}
			}
		}
		res = max(res, cnt);
	}
	cout << res << "\n";
}

*/