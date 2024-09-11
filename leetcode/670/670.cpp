#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string maximumS(string num)
    {
        if (num.size() == 1)
            return num;
        string &ss = num;
        int n = ss.size();
        int maxI = n;
        int maxVal = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (ss[i] - '0' > maxVal)
            {
                maxVal = ss[i] - '0';
                maxI = i;
            }
        }
        if (maxI == 0 || maxVal == ss[0] - '0')
        {
            string newSs = ss[0] + maximumS(ss.substr(1, n - 1));
            return newSs;
        }
        else
        {
            swap(ss[0], ss[maxI]);
            return ss;
        }
    }
    int maxminimumSwap(int num)
    {
        return stoi(maximumS(to_string(num)));
    }
};

int main()
{
    Solution s;
    cout << s.maximumS("1001") << endl;
    return 0;
}