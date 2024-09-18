#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int M, N;
    cin >> M >> N;
    queue<int> q;
    map<ll, bool> mp;
    ll count = 0;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        if (mp[x] == 1)
            continue;
        else
        {
            mp[x] = 1;
            count++;
            q.push(x);
            if (q.size() > M)
            {
                mp[q.front()] = 0;
                q.pop();
            }
        }
    }
    cout << count << endl;
}

int main()
{
    solve();
    return 0;
}