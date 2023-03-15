#include <iostream>
#include <cstring>
using namespace std;

int step[8][2] = {{1, 2}, {2, 1}, {1, -2}, {2, -1}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}};
// 写出所有可能的走法
int whe[11][11]; // 判断

int n, m;        // 棋盘大小
int map[11][11]; // 棋盘

int count; // 计数器

void dfs(int x, int y, int steps)
{

    int i, nx, ny;
    if (steps == n * m)
    {
        count++;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        nx = x + step[i][0];
        ny = y + step[i][1];
        if (nx < n && nx >= 0 && ny < m && ny >= 0 && !whe[nx][ny])
        {
            whe[nx][ny] = 1;
            dfs(nx, ny, steps + 1);
            whe[nx][ny] = 0; // 检测一次后重置
        }
    }
}

int main()
{
    int x, y;
    int k;
    cin >> k;
    while (k--)
    {
        count = 0;
        memset(whe, 0, sizeof(whe));
        cin >> n >> m >> x >> y;
        whe[x][y] = 1; // 初始坐标
        dfs(x, y, 1);
        cout << count << endl;
    }
    return 0;
}