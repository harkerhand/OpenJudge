#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve()
{
    int z, y, x;
    cin >> z >> y >> x;
    y += z / 3;
    z %= 3;
    x += y / 3;
    y %= 3;
    return 18 * x + 3 * y + z;
}

signed main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = {i + 1, solve()};
    }
    sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.second == b.second ? a.first < b.first : a.second > b.second; });
    for (int i = 0; i < n; i++)
    {
        cout << a[i].first << " ";
    }
}