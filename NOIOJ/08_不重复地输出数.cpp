#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    set<int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    for (auto i : s)
    {
        cout << i << " ";
    }
}

int main()
{
    solve();
    return 0;
}