#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll R;
    cin >> R;
    ll n;
    cin >> n;
    vector<ll> aaa(R + 1), saaa(R + 1);
    for (ll i = 0; i < n; i++)
    {
        ll x1, y1, w, h;
        cin >> x1 >> y1 >> w >> h;
        for (ll j = x1 + 1; j <= x1 + w; j++)
        {
            aaa[j] += h;
        }
    }
    for (ll i = 1; i <= R; i++)
    {
        saaa[i] = saaa[i - 1] + aaa[i];
    }
    ll left = 1;
    ll right = R;
    while (left < right)
    {
        ll mid = left + (right - left) / 2;
        ll rs = saaa[R] - saaa[mid];
        if (saaa[mid] >= rs)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    while (left < R && saaa[left + 1] == saaa[left])
        left++;
    cout << left << endl;
}

int main()
{
    solve();
    return 0;
}