#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int x = 0, y = 0;
        int xx = matrix[0].size() - 1, yy = matrix.size() - 1;
        vector<int> res;
        int front = 0;
        // right = 0 down = 1 left = 2 up = 3
        while (res.size() < matrix.size() * matrix[0].size())
        {
            if (front == 0)
            {
                for (int i = x; i <= xx; ++i)
                {
                    res.push_back(matrix[y][i]);
                }
                ++y;
            }
            else if (front == 1)
            {
                for (int i = y; i <= yy; ++i)
                {
                    res.push_back(matrix[i][xx]);
                }
                --xx;
            }
            else if (front == 2)
            {
                for (int i = xx; i >= x; --i)
                {
                    res.push_back(matrix[yy][i]);
                }
                --yy;
            }
            else
            {
                for (int i = yy; i >= y; --i)
                {
                    res.push_back(matrix[i][x]);
                }
                ++x;
            }
            front = (front + 1) % 4;
        }
        return res;
    }
};

int main()
{
    Solution ss;
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> res = ss.spiralOrder(matrix);
    for (auto i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}