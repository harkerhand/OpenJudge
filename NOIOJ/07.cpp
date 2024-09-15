#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n;
    vector<int> aaa;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        aaa.push_back(a);
    }
    sort(aaa.begin(), aaa.end());
    int target;
    cin >> target;
    for (int i = 0; i < n - 1; i++)
    {
        int delta = target - aaa[i];
        int left = i + 1;
        int right = n - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (aaa[mid] == delta)
            {
                cout << aaa[i] << " " << aaa[mid] << endl;
                return;
            }
            else if (aaa[mid] < delta)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    cout << "No" << endl;
}

int main()
{
    solve();
    return 0;
}