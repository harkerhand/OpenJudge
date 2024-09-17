#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int l;
    cin >> l;
    vector<int> want(l);
    for (int i = 0; i < l; i++)
    {
        cin >> want[i];
    }
    for (int i = 0; i < l; i++)
    {
        int left = 0;
        int right = n - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] < want[i])
            {
                left = mid + 1;
            }
            else if (nums[mid] == want[i])
            {
                left = mid;
                break;
            }
            else
            {
                right = mid - 1;
            }
        }
        int ans;
        int delta = 100000000;
        if (left > 0)
            if (abs(nums[left - 1] - want[i]) < delta)
            {
                delta = abs(nums[left - 1] - want[i]);
                ans = nums[left - 1];
            }
        if (abs(nums[left] - want[i]) < delta)
        {
            delta = abs(nums[left] - want[i]);
            ans = nums[left];
        }
        if (left < n - 1)
            if (abs(nums[left + 1] - want[i]) < delta)
            {
                ans = nums[left + 1];
            }
        cout << ans << endl;
    }
}

int main()
{
    solve();
}