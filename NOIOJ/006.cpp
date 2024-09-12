#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> aaa;

int check(int mid, int mon)
{
    int len = aaa.size();
    int sum = 0, cnt = 1;
    for (int i = 0; i < len; i++)
    {
        if (sum + aaa[i] <= mid)
        {
            sum += aaa[i];
        }
        else if (mid < aaa[i])
        {
            return -1;
        }
        else
        {
            cnt++;
            sum = aaa[i];
        }
        if (cnt > mon)
            return -1;
    }
    return 1;
}

void solve()
{
    int n, mon;
    cin >> n >> mon;
    int maxx = 0, total = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        maxx = max(a, maxx);
        total += a;
        aaa.push_back(a);
    }
    int left = maxx, right = total;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (check(mid, mon) == -1)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    cout << left;
}

int main()
{
    solve();
    return 0;
}