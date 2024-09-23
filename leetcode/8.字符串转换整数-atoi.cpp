#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution
{
public:
    int myAtoi(string s)
    {
        long ans = 0;
        bool flag = true;
        bool flag2 = false;
        for (auto i : s)
        {
            if (i == ' ')
                continue;
            else if (i >= '0' && i <= '9')
            {
                ans = ans * 10 + (i - '0');
                flag2 = true;
            }
            else if (ans > INT_MAX)
            {
                return flag ? INT_MAX : INT_MIN;
            }
            else if (i == '-')
            {
                flag = false;
                continue;
            }
            else
                break;
        }
        return flag ? ans : -ans;
    }
};
// @lc code=end
