#include<queue>
#include <iostream>
#include <tuple>
#include<cstdio>
#include<stdio.h>


using namespace std;

const int max_n = 55;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int n, m, a[max_n][max_n], visited[max_n][max_n], y, x;
int countx = 0;

void jaegi(int index1, int index2)
{   
    countx++;
    visited[index1][index2] = true;

    for (int i = 0; i < 4; i++)
    {
        int ny = index1 + dy[i];
        int nx = index2 + dx[i];
        if (ny < 0 || ny >= m || nx < 0 || nx >= n || a[ny][nx] == 0) continue;
        if (visited[ny][nx]) continue;
        jaegi(ny, nx);
    }
}
int main() {


    int oo, o2;
    cin >> oo;

    for (int i = 0; i < oo; i++)
    {
        cin >> n >> m >> o2;
        for (int j = 0; j < o2; j++)
        {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            a[temp1][temp2] = 1;
        }

        for (int k = 0; k < m; k++)
        {
            for (int k1 = 0; k1 < n; k1++)
            {
               if(visited[k][k1] == 0 && a[k][k1] == 1 ) jaegi(k,k1);
            }
        }

        cout << countx << "\n";
    }

    return 0;
}
