#include <iostream>
using namespace std;

int apple(int m, int n)
{
    if (m < n)
    {
        return apple(m, m);
    }
    if (m == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    return apple(m - n, n) + apple(m, n - 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        cout << apple(m, n) << endl;
    }
    return 0;
}