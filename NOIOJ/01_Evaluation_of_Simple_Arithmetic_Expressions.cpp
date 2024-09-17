#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    string s = "", ss;
    while (cin >> ss)
    {
        s += ss;
    }

    cin >> s;
    stack<ll> nums;
    char op;
    string num = "";
    for (auto i : s)
    {
        if (i != ' ')
        {
            if (i >= '0' && i <= '9')
            {
                num += i;
            }
            else
            {
                nums.push(stoi(num));
                num = "";
                op = i;
            }
        }
    }
    ll ans;
    if (op == '+')
    {
        ans = nums.top() + stoi(num);
    }
    else if (op == '-')
    {
        ans = nums.top() - stoi(num);
    }
    else if (op == '*')
    {
        ans = nums.top() * stoi(num);
    }
    else if (op == '/')
    {
        ans = nums.top() / stoi(num);
    }
    else if (op == '%')
    {
        ans = nums.top() % stoi(num);
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}