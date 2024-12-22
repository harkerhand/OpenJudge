#include <iostream>
#include <string>
using namespace std;
bool c(string &n, string &m)
{
    if (n.length() != m.length())
        return false;
    string s1s1 = n + n;
    return s1s1.find(m) != string::npos;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string g, h;
        cin >> g >> h;
        cout << (c(g, h) ? "YES" : "NO") << endl;
    }
    return 0;
}
