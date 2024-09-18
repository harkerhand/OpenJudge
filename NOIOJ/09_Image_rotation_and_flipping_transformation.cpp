#include <bits/stdc++.h>
using namespace std;
#define ll long long

void doo(vector<vector<int>> &a, char A)
{
    vector<vector<int>> b;
    if (A == 'A')
    {
        for (int i = 0; i < a[0].size(); i++)
        {
            b.push_back(vector<int>());
            for (int j = a.size() - 1; j >= 0; j--)
            {
                b[i].push_back(a[j][i]);
            }
        }
        a = b;
    }
    else if (A == 'B')
    {
        for (int i = 0; i < a[0].size(); i++)
        {
            b.push_back(vector<int>());
            for (int j = 0; j < a.size(); j++)
            {
                b[i].push_back(a[j][a[0].size() - 1 - i]);
            }
        }
        a = b;
    }
    else if (A == 'C')
    {
        for (auto &i : a)
        {
            reverse(i.begin(), i.end());
        }
    }
    else if (A == 'D')
    {
        reverse(a.begin(), a.end());
    }
}

void solve()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    string s;
    cin >> s;
    for (auto i : s)
    {
        doo(a, i);
    }
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    solve();
    return 0;
}