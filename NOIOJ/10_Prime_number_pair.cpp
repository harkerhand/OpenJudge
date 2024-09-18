#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= std::sqrt(n); ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    bool ok = 0;
    for (int i = 2; i <= n - 2; ++i)
    {
        if (isPrime(i) && isPrime(i + 2))
        {
            cout << i << " " << i + 2 << endl;
            ok = 1;
        }
    }
    if (!ok)
        cout << "empty" << endl;
}

int main()
{
    solve();
    return 0;
}