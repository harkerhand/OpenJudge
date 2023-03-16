#include <iostream>
#include <cstring>
using namespace std;

char map[101][101];

int go[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int vis[101][101];

int xa, ya, xb, yb, temp, k, n;
void whe(int x, int y)
{
    if (x >= n || y >= n || x < 0 || y < 0 || vis[x][y] || map[x][y] == '#')
    {
        return;
    }                       // 走错了
    if (x == xb && y == yb) // 走到了
    {
        temp = 1;
        return;
    }
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        whe(x + go[i][0], y + go[i][1]);
    }
}

int main()
{
    cin >> k;

    while (k--)
    {
        memset(map, 0, sizeof(map));
        memset(vis, 0, sizeof(vis));
        temp = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> map[i][j];
            }
        }
        cin >> xa >> ya >> xb >> yb;
        if (map[xa][ya] == '#' || map[xb][yb] == '#')
        {
            cout << "NO" << endl;
        }
        else
        {
            whe(xa, ya);
            if (temp)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}