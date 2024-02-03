#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        if (coordinates[0][0] == coordinates[1][0])
        {
            for (int i = 2; i < coordinates.size(); ++i)
            {
                if (coordinates[i][0] != coordinates[0][0])
                    return 0;
                return 1;
            }
        }
        double k = 1.0 * (coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
        double b = coordinates[0][1] - k * coordinates[0][0];
        for (int i = 2; i < coordinates.size(); ++i)
        {
            if (k * coordinates[i][0] + b != coordinates[i][1])
                return 0;
        }
        return 1;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> coordinates = {{2, 1}, {4, 2}, {6, 3}};
    cout << sol.checkStraightLine(coordinates) << endl;
}