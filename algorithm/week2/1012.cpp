/*
#include<iostream>
#include<algorithm>

using namespace std;

int a[55][55], visit[55][55];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int n, m;

void dfs(int y, int x)
{
	visit[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
		if (!visit[ny][nx] && a[ny][nx]) dfs(ny, nx);
	}
}


int main(void)
{
	int ret = 0;
	int g;
	cin >> g;

	for (int i = 0; i < g; i++)
	{

		ret = 0;
		fill(&a[0][0], &a[0][0] + 55 * 55, 0);
		fill(&visit[0][0], &visit[0][0] + 55 * 55, 0);
		int temp;

		cin >> m >> n >> temp;

		for (int j = 0; j < temp; j++)
		{
			int q1, q2;
			cin >> q1 >> q2;
			a[q2][q1] = 1;
		}

		for (int j = 0; j < n; j++)
		{
			for (int j2 = 0; j2 < m; j2++)
			{
				if (a[j][j2] && !visit[j][j2])
				{
					dfs(j, j2);
					ret++;
				}
			}
		}

		cout << ret << "\n";
	}
}

*/