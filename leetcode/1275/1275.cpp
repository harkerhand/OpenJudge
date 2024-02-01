#include <iostream>
#include <vector>
#include <array>
#include <string>
using namespace std;

class Solution
{
public:
    string tictactoe(vector<vector<int>> &moves)
    {
        array<array<char, 3>, 3> map = {0};
        bool A_or_B = 1;
        int count = moves.size();
        for (auto &i : moves)
        {
            map[i[0]][i[1]] = A_or_B ? 'X' : 'O';
            A_or_B = !A_or_B;
        }
        int win = 0;
        for (int i = 0; i < 3; i++)
        {
            if (map[i][0] == map[i][1] && map[i][1] == map[i][2])
            {
                if (map[i][0] == 'X')
                    win = 1;
                else
                    win = -1;
                break;
            }
            if (map[0][i] == map[1][i] && map[1][i] == map[2][i])
            {
                if (map[0][i] == 'X')
                    win = 1;
                else
                    win = -1;
                break;
            }
        }
        if ((map[0][0] == map[1][1] && map[1][1] == map[2][2]) ||
            (map[2][0] == map[1][1] && map[1][1] == map[0][2]))
        {
            if (map[1][1] == 'X')
                win = 1;
            else
                win = -1;
        }
        if (win != 0)
        {
            return win > 0 ? "A" : "B";
        }
        return count == 9 ? "Draw" : "Pending";
    }
};
int main()
{
    Solution aa;
    vector<vector<int>> ss = {{0, 0}, {1, 1}, {0, 1}, {0, 2}, {1, 0}, {2, 0}};
    cout << aa.tictactoe(ss);
}