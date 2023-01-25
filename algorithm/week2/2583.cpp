#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define y1 aaaa

int visit[101][101], a[101][101];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int n, m, k, x1, x2, y1, y2;

vector<int> ret;

int dfs(int y, int x)
{
	visit[y][x] = true;
	int ret = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || nx >= n || ny >= m )continue;
		if (visit[ny][nx] || a[ny][nx]==1) continue;
		ret += dfs(ny, nx);
	}

	return ret;
}

int main(void)
{
	cin >> m >> n >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		for (int x = x1; x < x2; x++)
		{
			for (int y = y1; y < y2; y++)
			{
				a[y][x] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] != 1 && visit[i][j] == 0)
			{
				ret.push_back(dfs(i, j));
			}
		}
	}
	
	sort(ret.begin(), ret.end());

	cout << ret.size() << "\n";
	for (auto q : ret)
	{
		cout << q << "\t";
	}
}