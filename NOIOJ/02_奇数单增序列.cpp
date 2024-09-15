#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int l;
    cin >> l;
    vector<int> aa;
    for (int i = 1; i <= l; i++)
    {
        int a;
        cin >> a;
        if (a % 2 == 1)
        {
            aa.push_back(a);
        }
    }
    sort(aa.begin(), aa.end());
    for (int i = 0; i + 1 < aa.size(); i++)
    {
        cout << aa[i] << ",";
    }
    cout << aa[aa.size() - 1];
}

int main()
{
    solve();
}