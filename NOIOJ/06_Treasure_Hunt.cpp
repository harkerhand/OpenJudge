#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct room
{
    bool isis;
    int num;
};

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<vector<room>> lou(N, vector<room>(M + 1));
    for (int i = 0; i < N; i++)
    {
        int l = 0;
        for (int j = 0; j < M; j++)
        {
            cin >> lou[i][j].isis >> lou[i][j].num;
            if (lou[i][j].isis == 1)
                l++;
        }
        lou[i][M].num = l;
    }
    int num;
    cin >> num;
    int total = 0;
    for (int i = 0; i < N; i++)
    {
        int begi = lou[i][num].num;
        int count = 0;
        total += begi;
        total %= 20123;
        for (int j = num;; j++)
        {
            if (j == M)
            {
                j = 0;
            }
            if (lou[i][j].isis)
            {
                count++;
            }
            if (count == (begi - 1) % lou[i][M].num + 1)
            {
                num = j;
                break;
            }
        }
    }
    cout << total % 20123;
}

int main()
{
    solve();
    return 0;
}