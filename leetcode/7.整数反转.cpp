#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        long long res = 0;
        bool right = (x >= 0);
        x = abs(x);
        while (x)
        {
            res = res * 10 + x % 10;
            x /= 10;
        }
        if (res > INT_MAX)
            return 0;
        return right ? res : -res;
    }
};
// @lc code=end
