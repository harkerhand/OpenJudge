#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        int x = 0, y = 0;
        int front = 0;
        int go[4][2] = {0, 1, -1, 0, 0, -1, 1, 0};
        for (auto i : instructions)
        {
            if (i == 'G')
            {
                x += go[front][0];
                y += go[front][1];
            }
            if (i == 'L')
            {
                i == 0 ? i = 3 : --i;
            }
            if (i == 'R')
            {
                i == 3 ? i = 0 : ++i;
            }
        }
        return (x || y) ? false : true;
    }
};
int main()
{
    Solution aa;
    cout << aa.isRobotBounded("GGLLGG");
}