#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static string add(string num1, string num2)
    {
        if (num1 == "")
            return num2;
        if (num2 == "")
            return num1;

        bool up = 0;
        string newNum = "";
        int len1 = num1.length(), len2 = num2.length();
        for (int i = 1; i <= len1 || i <= len2; ++i)
        {
            int s1 = i <= len1 ? num1[len1 - i] - '0' : 0;
            int s2 = i <= len2 ? num2[len2 - i] - '0' : 0;
            newNum += char((s1 + s2 + up) % 10 + '0');
            up = (s1 + s2 + up) / 10;
        }
        if (up)
        {
            newNum += '1';
        }
        reverse(newNum.begin(), newNum.end());
        return newNum;
    }

    static string charMultiply(char num1, string num2)
    {
        if (num1 == '0' || num2 == "0")
            return "0";
        if (num1 == '1')
            return num2;
        string newNum;
        int up = 0;
        for (int i = num2.length() - 1; i >= 0; --i)
        {
            newNum += char(((num2[i] - '0') * (num1 - '0') + up) % 10 + '0');
            up = ((num2[i] - '0') * (num1 - '0') + up) / 10;
        }
        if (up)
        {
            newNum += char(up + '0');
        }
        reverse(newNum.begin(), newNum.end());
        return newNum;
    }

    static string multiply(string num1, string num2)
    {

        string ans = "";
        for (int i = num2.length() - 1; i >= 0; --i)
        {
            string temp = charMultiply(num2[i], num1);
            temp.append(num2.length() - 1 - i, '0');
            ans = add(ans, temp);
        }

        while (ans.length() > 1 && ans[0] == '0')
        {
            ans = ans.substr(1);
        }
        return ans;
    }
};

int main()
{
    cout << Solution::multiply("1", "992") << endl;
    return 0;
}