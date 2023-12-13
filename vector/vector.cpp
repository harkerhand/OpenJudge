#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Juzhen
{
public:
    explicit Juzhen(vector<vector<double>> &in)
    {
        juzhen = in;
        row = in.size();
        line = in[0].size();
    }
    explicit Juzhen(unsigned int rowIN, unsigned int lineIN)
    {
        row = rowIN;
        line = lineIN;
        juzhen.resize(rowIN);
        for (auto &i : juzhen)
        {
            i.resize(lineIN);
        }
        toZero();
    }
    explicit Juzhen()
    {
        row = 1;
        line = 1;
        juzhen = {{0}};
    }

    Juzhen operator+(const Juzhen &b)
    {
        Juzhen temp(this->row, this->line);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < line; j++)
            {
                temp.juzhen[i][j] = this->juzhen[i][j] + b.juzhen[i][j];
            }
        }
        return temp;
    }

    Juzhen zhuanzhi()
    {
        Juzhen temp;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp.juzhen[i][j] = this->juzhen[j][i];
            }
        }
        return temp;
    }

    friend ostream &operator<<(ostream &output, const Juzhen &temp)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                output << setw(5) << temp.juzhen[i][j];
            }
            output << endl;
        }
        return output;
    }

    void toZero()
    {
        for (unsigned int i = 0; i < row; i++)
        {
            for (unsigned int j = 0; j < line; j++)
            {
                juzhen[i][j] = 0;
            }
        }
    }

private:
    unsigned int row;
    unsigned int line;
    vector<vector<double>> juzhen;
};

int main()
{
    vector<vector<double>> a = {{3, 5, 7}, {12, 13, 6}};
    vector<vector<double>> b = {{4, 8, 10}, {6, 13, 16}};
    Juzhen juzhenA(a);
    Juzhen juzhenB(b);
    Juzhen juzhenC = juzhenA + juzhenB;
    cout << juzhenC;

    return 0;
}