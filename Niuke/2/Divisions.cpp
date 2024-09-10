#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int k;
    cin >> k;
    if (k == 0)
    {
        cout << "12\n1 1 4 5 1 4 1 1 4 5 1 4";
        return;
    }

    if (k == 1)
    {
        cout << "6\n1 1 4 5 1 4";
        return;
    }

    vector<int> ans;
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        if (k & (1 << i))
        {
            count++;
            for (int j = 0; j < i; j++)
                ans.push_back(count);
        }
    }
    int x = count - 1;
    for (int i = 1; i <= x; i++)
    {
        ans.push_back(++count);
    }
    cout << ans.size() << endl;
    for (auto i : ans)
    {
        cout << i << " ";
    }
}

int main()
{
    solve();
}