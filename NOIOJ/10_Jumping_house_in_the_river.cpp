#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> aaa;

bool check(int mid, int n)
{
    int bef = aaa[0];
    int cnt = 0;
    for (int i = 1; i < aaa.size(); i++)
    {
        if (aaa[i] - bef < mid)
        {
            cnt++;
        }
        else
        {
            bef = aaa[i];
        }
    }
    return cnt <= n;
}

void solve()
{
    int L, M, N;
    cin >> L >> M >> N;
    aaa.push_back(0);
    for (int i = 0; i < M; i++)
    {
        int x;
        cin >> x;
        aaa.push_back(x);
    }
    aaa.push_back(L);
    int left = 0, right = L;
    while (left < right)
    {
        int mid = (left + right + 1) / 2;
        if (check(mid, N))
        {
            left = mid;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << left;
}

int main()
{
    solve();
    return 0;
}