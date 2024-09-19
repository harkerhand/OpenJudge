#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        auto dp = vector(n + n, vector(n, vector(n, INT_MIN)));
        dp[0][0][0] = grid[0][0];
        for (int step = 1; step < n * 2 - 1; step++)
        {
            for (int x1 = 0; x1 < n; x1++)
            {
                int y1 = step - x1;
                if (y1 < 0 || y1 >= n || grid[x1][y1] == -1)
                    continue;
                for (int x2 = 0; x2 < n; x2++)
                {
                    int y2 = step - x2;
                    if (y2 < 0 || y2 >= n || grid[x2][y2] == -1)
                        continue;
                    int &res = dp[step][x1][x2];
                    auto &prev = dp[step - 1];
                    res = max(res, prev[x1][x2]);
                    if (x1)
                        res = max(res, prev[x1 - 1][x2]);
                    if (x2)
                        res = max(res, prev[x1][x2 - 1]);
                    if (x1 && x2)
                        res = max(res, prev[x1 - 1][x2 - 1]);
                    res += grid[x1][y1];
                    if (x1 != x2)
                        res += grid[x2][y2];
                }
            }
        }
        return max(0, dp[n * 2 - 2][n - 1][n - 1]);
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{1, 1, -1}, {1, -1, 1}, {-1, 1, 1}};
    cout << sol.cherryPickup(grid) << endl;
    return 0;
}