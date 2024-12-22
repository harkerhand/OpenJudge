// P1009

#include <bits/stdc++.h>
using namespace std;
#define int long long

struct BIGINT
{
    vector<int> nums;
    BIGINT(const vector<int> &numsIN)
    {
        nums = numsIN;
        while (nums.back() == 0 && nums.size() > 1)
        {
            nums.resize(nums.size() - 1);
        }
    }
    BIGINT(string s)
    {
        int n = s.length();
        while (n > 8)
        {
            string back = s.substr(n - 8, 8);
            nums.push_back(stoi(back));
            s = s.substr(0, n - 8);
            n -= 8;
        }
        nums.push_back(stoi(s));
    }
    BIGINT operator+(const BIGINT &b)
    {
        vector<int> newNums;
        int i = 0;
        for (; i < nums.size() && i < b.nums.size(); i++)
        {
            newNums.push_back(nums[i] + b.nums[i]);
        }
        for (int j = i; j < nums.size(); j++)
        {
            newNums.push_back(nums[j]);
        }
        for (int j = i; j < b.nums.size(); j++)
        {
            newNums.push_back(b.nums[j]);
        }
        for (int j = 0; j < newNums.size(); j++)
        {
            if (newNums[j] >= 1e8)
            {
                if (j + 1 == newNums.size())
                {
                    newNums.push_back(0);
                }
                newNums[j] -= 1e8;
                newNums[j + 1]++;
            }
        }
        return BIGINT(newNums);
    }

    friend ostream &operator<<(ostream &os, const BIGINT &b)
    {
        os << b.nums.back();
        for (int i = b.nums.size() - 2; i >= 0; i--)
        {
            os << setw(8) << setfill('0') << b.nums[i];
        }
        return os;
    }

    BIGINT operator*(const BIGINT &b)
    {
        vector<int> shushi(nums.size() + b.nums.size(), 0);
        for (int i = 0; i < b.nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                shushi[i + j] += nums[j] * b.nums[i];
            }
        }
        for (int i = 0; i < shushi.size(); i++)
        {
            if (shushi[i] >= 1e8)
            {
                if (i + 1 == shushi.size())
                {
                    shushi.push_back(0);
                }
                shushi[i + 1] += shushi[i] / 1e8;
                shushi[i] %= (int)1e8;
            }
        }
        return BIGINT(shushi);
    }
};

signed main()
{
    int a;
    cin >> a;
    vector<BIGINT> fracs;
    vector<BIGINT> sums;
    fracs.push_back(BIGINT("1"));
    sums.push_back(BIGINT("1"));
    for (int i = 2; i <= a; i++)
    {
        fracs.push_back(fracs.back() * BIGINT(to_string(i)));
        sums.push_back(sums.back() + fracs.back());
    }
    cout << sums.back() << endl;
}