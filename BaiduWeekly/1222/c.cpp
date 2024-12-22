#include <bits/stdc++.h>
using namespace std;

bool isEq(vector<int> &a, vector<int> &b, int al, int ar, int bl, int br)
{
    for (int i = al, bb = bl; i <= ar; i++, bb++)
    {
        if (a[i] != b[bb])
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> b[i];
    }
    if (N % 2 == 0)
    {
        int l = N / 2 - 1;
        int r = N / 2;
        for (; r < N;)
        {
            if (a[l] == b[l] && a[r] == b[r])
            {
                l--;
                r++;
            }
            else if (a[l] != b[l] && a[r] != b[r])
            {
                break;
            }
            else
            {
                cout << "No" << endl;
                return;
            }
        }
        // 停止的l, r是不相等的临界
        if (r == N)
        {
            cout << "Yes" << endl;
            return;
        }
        if (isEq(a, b, 0, l, r, N - 1) && isEq(a, b, r, N - 1, 0, l))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    if (N % 2 == 1)
    {
        int l = N / 2;
        int r = N / 2;
        for (; r < N;)
        {
            if (a[l] == b[l] && a[r] == b[r])
            {
                l--;
                r++;
            }
            else if (a[l] != b[l] && a[r] != b[r])
            {
                break;
            }
            else
            {
                cout << "No" << endl;
                return;
            }
        }
        // 停止的l, r是不相等的临界
        if (r == N)
        {
            cout << "Yes" << endl;
            return;
        }
        if (isEq(a, b, 0, l, r, N - 1) && isEq(a, b, r, N - 1, 0, l))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}
signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}