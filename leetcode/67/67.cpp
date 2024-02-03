#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        bool up = 0;
        string newStr = "";
        int len_A = a.length(), len_B = b.length();
        for (int i = 1; i <= len_A || i <= len_B; ++i)
        {
            int aa = i <= len_A ? (a[len_A - i] - '0') : 0;
            int bb = i <= len_B ? (b[len_B - i] - '0') : 0;
            newStr += (aa + bb + up) % 2 ? '1' : '0';
            up = (aa + bb + up) / 2;
        }
        newStr += up ? "1" : "";
        reverse(newStr.begin(), newStr.end());
        return newStr;
    }
};

int main()
{
    Solution sol;
    string a = "11", b = "1";
    cout << sol.addBinary(a, b) << endl;
}