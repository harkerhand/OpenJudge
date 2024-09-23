#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n < 2)
            return s;
        int maxLen = 1;
        int begin = 0;
        auto dp = vector(n, vector(n, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }
        for (int j = 1; j < n; j++)
        {
            for (int i = 0; i < j; i++)
            {
                if (s[i] != s[j])
                {
                    dp[i][j] = false;
                }
                else
                {
                    if (j - i < 3)
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if (dp[i][j] && j - i + 1 > maxLen)
                {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};
// @lc code=end
