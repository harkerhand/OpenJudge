#include <iostream>
using namespace std;

int ans[1000010] = {1, 2};

int main()
{
    int n;
    for (int i = 2; i < 1000000; i++)
    {
        ans[i] = (ans[i - 1] * 2 + ans[i - 2]) % 32767;
    }
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        cout << ans[m - 1] << endl;
    }

    return 0;
}