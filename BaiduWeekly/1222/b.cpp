#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    // 行前缀和
    vector<vector<int>> s(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        s[i][0] = a[i][0];
        for (int j = 1; j < n; j++)
            s[i][j] = s[i][j - 1] + a[i][j];
    }
    // 列前缀和
    vector<vector<int>> t(n, vector<int>(n));
    for (int j = 0; j < n; j++)
    {
        t[0][j] = a[0][j];
        for (int i = 1; i < n; i++)
            t[i][j] = t[i - 1][j] + a[i][j];
    }
    int mx = LLONG_MIN;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int ans = 100;
            ans += s[0][j];
            ans += s[i][j];
            ans += t[i][0];
            ans += t[i][j];
            ans -= a[i][j];
            ans -= a[0][j];
            ans -= a[i][0];
            mx = max(mx, ans);
        }
    }
    cout << mx << endl;
}