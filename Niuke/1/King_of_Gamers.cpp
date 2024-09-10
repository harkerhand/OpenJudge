#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, a, b;
    cin >> n >> a >> b;
    long long ans = 1;
    ans += (n - 1) * a / b;
    cout << ans << endl;
}
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}