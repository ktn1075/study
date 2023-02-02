#include <iostream>
#include<vector>

using namespace std;

int nx[4] = { 0,1,0,-1 };
int ny[4] = { -1,0,1,0 };
int pan[8][8] = { 0 };
int check = 0;
int rookPointY = 0;
int rookPointX = 0;
int rookCount = 0;

vector<pair<int,int>> lookpoint;

int main() {

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int temp;
            cin >> temp;
            if (temp == 2)
            {
                lookpoint.push_back({ i,j });
            }
            pan[i][j] = temp;
        }
    }

    for (auto lc : lookpoint) 
    {
        for (int i = 0; i < 4; i++)
        {
            int py = lc.first;
            int px = lc.second;
            while (true)
            {
                py += ny[i];
                px += nx[i];
                if (py < 0 || px < 0 || py > 7 || px > 7 || pan[py][px] == 3) break;
                if (pan[py][px] == 1)
                {
                    cout << 1;
                    return 0;
                }
            }
        }
    }

    cout << 0;
    return 0;
}