#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        string ans = "";
        if (s.size() <= numRows || numRows == 1)
        {
            return s;
        }
        for (int i = 0; i < numRows; i++)
        {
            if (i == 0)
            {
                for (int j = 0; j < s.size(); j += numRows * 2 - 2)
                {
                    ans += s[j];
                }
            }
            if (i == numRows - 1)
            {
                for (int j = numRows - 1; j < s.size(); j += numRows * 2 - 2)
                {
                    ans += s[j];
                }
            }
            if (i > 0 && i < numRows - 1)
            {
                for (int j = i, k = numRows * 2 - 2 - i; j < s.size() || k < s.size(); j += numRows * 2 - 2, k += numRows * 2 - 2)
                {
                    if (j < s.size())
                    {
                        ans += s[j];
                    }
                    if (k < s.size())
                    {
                        ans += s[k];
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
