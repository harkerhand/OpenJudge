#include <iostream>
using namespace std;

long long to10(int a, int b)
{ // a是数字，b是进制
    long long ans = 0;
    int temp;
    long long x = 1;
    while (a)
    {
        temp = a % 10;
        ans += temp * x;
        x *= b;
        a /= 10;
    }
    return ans;
}

int max(int a)
{
    int temp;
    int max = 0;
    while (a)
    {
        temp = a % 10;
        a /= 10;
        if (temp > max)
        {
            max = temp;
        }
    }
    return max;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int m = 0;
    if (max(a) > m)
    {
        m = max(a);
    }
    if (max(b) > m)
    {
        m = max(b);
    }
    if (max(c) > m)
    {
        m = max(c);
    }

    for (int i = m + 1; i; i++)
    {
        if (to10(a, i) * to10(b, i) == to10(c, i))
        {
            cout << i;
            break;
        }
        if (i == 16)
        {
            cout << 0;
            break;
        }
    }
    return 0;
}