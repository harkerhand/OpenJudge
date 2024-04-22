#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isGood(vector<vector<int>> &map, int x, int y)
    {
        if (x == 0 || x == map.size() - 1)
            return 0;
        bool leftGood = 0;
        bool rightGood = 0;
        for (int i = x; i >= 0; i--)
        {
            if (map[i][y] == 1)
            {
                leftGood = 1;
                break;
            }
        }
        for (int i = x; i < map.size(); i++)
        {
            if (map[i][y] == 1)
            {
                rightGood = 1;
                break;
            }
        }
        return leftGood && rightGood;
    }

    int findMax(vector<int> &height)
    {
        int maxI = -1;
        for (auto i : height)
        {
            maxI = max(maxI, i);
        }
        return maxI;
    }

    int trap(vector<int> &height)
    {
        int xLen = height.size();
        int yLen = findMax(height);
        vector<vector<int>> map(xLen, vector<int>(yLen));
        for (int i = 0; i < xLen; i++)
        {
            for (int j = 0; j < height[i]; j++)
            {
                map[i][j] = 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < yLen; i++)
        {
            for (int j = 0; j < xLen; j++)
            {
                if (map[j][i] == 1)
                    continue;
                if (isGood(map, j, i) == 1)
                {
                    ans++;
                    map[j][i] = 1;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> height = {4, 2, 0, 3, 2, 5};
    cout << s.trap(height) << endl;
    return 0;
}