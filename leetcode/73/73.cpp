#include <iostream>
#include <vector>
#include <array>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<array<int, 2>> map;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    map.push_back({i, j});
                }
            }
        }
        for (auto i : map)
        {
            for (int x = 0; x < matrix[0].size(); ++x)
            {
                matrix[i[0]][x] = 0;
            }
            for (int y = 0; y < matrix.size(); ++y)
            {
                matrix[y][i[1]] = 0;
            }
        }
    }
};

int main()
{
}