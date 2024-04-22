#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
        {
            for (auto &j : nums)
            {
                if (j <= i && dp[i - j] < INT_MAX - dp[i])
                {
                    dp[i] += dp[i - j];
                }
            }
        }
        return dp[target];
    }
};

int main()
{
    // 测试代码
    Solution s;
    vector<int> nums = {1, 2, 3};
    int target = 4;
    cout << s.combinationSum4(nums, target) << endl; // 输出组合数
}