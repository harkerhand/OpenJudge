#include <bits/stdc++.h>
using namespace std;
#define ll long long
// @params a:密钥 b:密文
char abc(char a, char b)
{
    bool bB = 0;
    if (a <= 'z' && a >= 'a')
    {
        a = a - 'a' + 'A';
    }
    if (b <= 'z' && b >= 'a')
    {
        bB = 1;
        b = b - 'a' + 'A';
    }
    return (b - a + 26) % 26 + (bB ? 'a' : 'A');
}

void solve()
{
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < b.size(); i++)
    {
        cout << abc(a[i % a.size()], b[i]);
    }
}

int main()
{
    solve();
    return 0;
}