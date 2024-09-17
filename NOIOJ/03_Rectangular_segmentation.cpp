<<<<<<< HEAD
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
=======
<<<<<<< HEAD:NOIOJ/02_奇数单增序列.cpp
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
=======
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
}

int main()
{
    return 0;
>>>>>>> d57db79a3dc4a81d211f23028416d8d597b0f86d:NOIOJ/03_Rectangular_segmentation.cpp
>>>>>>> f2e2f572aec29ab15fe946cd7abf3984b0b619f9
}