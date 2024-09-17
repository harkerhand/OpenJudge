#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;
    double total;
    while (n--)
    {
        int len;
        cin >> len;
        int thi = ceil(len / 70.0);
        total += thi * 0.1;
    }
    cout << fixed << setprecision(1) << total << endl;
}

int main()
{
    solve();
    return 0;
}