/*
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, ret;

int a[10][10], visit[10][10];

vector<pair<int,int>> virus;
vector<pair<int, int>> walllist;

const int dx[] = { 0,1,0,-1 };
const int dy[] = { -1,0,1,0 };

 void dfs(int y,int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m || visit[ny][nx] || a[ny][nx] == 1) continue;
		visit[ny][nx] = 1;
		dfs(ny, nx);
	}

}

int solve() {
	fill(&visit[0][0], &visit[0][0] + 10 *10 ,0);

	for (pair<int, int> b : virus)
	{
		visit[b.first][b.second] = 1;
		dfs(b.first, b.second);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0 && !visit[i][j]) cnt++;
		}
	}
	return cnt;
}


int main(void)
{

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 2) virus.push_back({i,j});
			if (a[i][j] == 0) walllist.push_back({i,j});
 		}
	}
	
	for (int i = 0; i < walllist.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < j; k++) {
				a[walllist[i].first][walllist[i].second] = 1;
				a[walllist[j].first][walllist[j].second] = 1;
				a[walllist[k].first][walllist[k].second] = 1;
				ret = max(ret, solve());
				a[walllist[i].first][walllist[i].second] = 0;
				a[walllist[j].first][walllist[j].second] = 0;
				a[walllist[k].first][walllist[k].second] = 0;
			}
		}

	}

	cout << ret;
}
*/
