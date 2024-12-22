#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n;
    cin >> n;
    unordered_map<string, string> m;
    while (n--)
    {
        string a, b;
        cin >> a >> b;
        m[b] = a;
    }
    cin >> n;
    while (n--)
    {
        string a;
        cin >> a;
        cout << m[a] << endl;
    }
}