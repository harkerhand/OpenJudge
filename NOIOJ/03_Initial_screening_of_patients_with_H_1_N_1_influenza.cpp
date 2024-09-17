#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n, to = 0;
    cin >> n;
    while (n--)
    {
        string a;
        double b;
        bool c;
        cin >> a >> b >> c;
        if (b >= 37.5 && c)
        {
            cout << a << endl;
            to++;
        }
    }
    cout << to << endl;
}

int main()
{
    solve();
    return 0;
}