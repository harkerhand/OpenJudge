#include <iostream>
#include <cstring>
using namespace std;

char a[201];

int main()
{
    int k;
    cin >> k;
    int c;
    while (k--)
    {
        cin >> a;
        int len = strlen(a);
        c = 1;
        if (len >= 5)
        {
            int u = (a[len - 3] - '0') * 100 + (a[len - 2] - '0') * 10 + (a[len - 1] - '0');
            u %= 500;
            for (int i = 0; i < u; ++i)
            {
                c *= 2011;
                c %= 10000;
            }
        }
        else
        {
            int u = atof(a);
            for (int i = 0; i < u; ++i)
            {
                c *= 2011;
                c %= 10000;
            }
        }
        cout << c << endl;
    }
    return 0;
}