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
        // 将结果先声明为 long long，溢出时即时处理。
        // 不转换也有处理方式，但多了些心智负担。
        long long num = 0;
        int n = s.length();

        // 跳过前导空格
        int i = 0;
        while (i < n && s[i] == ' ')
            i++;
        if (i == n)
            return 0;

        // 判断正负，flag 用于最后与 num 相乘作为结果
        int flag = 1; // 无符号时为 1 (正)，i 不用前进
        if (s[i] == '-')
        {
            flag = -1;
            i++;
        }
        else if (s[i] == '+')
        {
            i++;
        }

        // 跳过前导 0
        while (i < n && s[i] == '0')
            i++;
        if (i == n)
            return 0;

        // 开始读取数字
        for (; i < n; i++)
        {
            char c = s[i];

            // 遇到除数字外的字符退出
            if (c < '0' || c > '9')
                break;

            // 得到无符号的新数字
            num = num * 10 + (c - '0');

            // 看带符号的新数字是否溢出或者到达最大/最小
            long long v = num * flag;
            if (v >= INT_MAX)
                return INT_MAX;
            if (v <= INT_MIN)
                return INT_MIN;
        }

        return num * flag;
    }
};
// @lc code=end
