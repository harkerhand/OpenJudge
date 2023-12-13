#include <vector>
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::ostream;
using std::setw;
using std::vector;

class Matrix
{
public:
    explicit Matrix(const vector<vector<double>> &in)
    {
        if (isMatrix(in))
        {
            matrix = in;
            row = in.size();
            line = in[0].size();
        }
        else
        {
            cout << "这不是一个矩阵\n";
            Matrix();
        }
    }
    explicit Matrix(unsigned int rowIN, unsigned int lineIN)
    {
        row = rowIN;
        line = lineIN;
        matrix.resize(rowIN);
        for (auto &i : matrix)
        {
            i.resize(lineIN);
        }
        toZero();
    }
    explicit Matrix()
    {
        row = 0;
        line = 0;
        matrix.resize(0);
    }

    Matrix operator+(const Matrix &b)
    {
        if (this->isIsotype(b))
        {
            Matrix temp(this->row, this->line);
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < line; j++)
                {
                    temp.matrix[i][j] = this->matrix[i][j] + b.matrix[i][j];
                }
            }
            return temp;
        }
        else
        {
            cout << "非法的相加\n";
            Matrix empty;
            return empty;
        }
    }

    Matrix operator-(const Matrix &b)
    {
        if (this->isIsotype(b))
        {
            Matrix temp(this->row, this->line);
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < line; j++)
                {
                    temp.matrix[i][j] = this->matrix[i][j] - b.matrix[i][j];
                }
            }
            return temp;
        }
        else
        {
            cout << "非法的相减\n";
            Matrix empty;
            return empty;
        }
    }

    Matrix transpose()
    {
        Matrix temp(this->line, this->row);
        for (int i = 0; i < line; i++)
        {
            for (int j = 0; j < row; j++)
            {
                temp.matrix[i][j] = this->matrix[j][i];
            }
        }
        return temp;
    }

    friend ostream &operator<<(ostream &output, const Matrix &temp)
    {
        for (int i = 0; i < temp.row; i++)
        {
            for (int j = 0; j < temp.line; j++)
            {
                output << setw(5) << temp.matrix[i][j];
            }
            output << endl;
        }
        return output;
    }

    // 同型
    bool isIsotype(const Matrix &b)
    {
        return this->row == b.row && this->line == b.line;
    }

    // 方阵
    bool isPhalanx()
    {
        return this->row == this->line;
    }

    // 归零
    void toZero()
    {
        for (unsigned int i = 0; i < row; i++)
        {
            for (unsigned int j = 0; j < line; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // 子式
    Matrix son(const unsigned int rowIN, const unsigned int lineIN)
    {
        Matrix temp(this->row - 1, this->line - 1);
        for (int i1 = 0, i2 = 0; i2 < this->row && i1 < this->row - 1; i1++, i2++)
        {
            if (i1 == rowIN - 1)
            {
                i2++;
            }
            if (i2 >= this->row)
            {
                break;
            }
            for (int j1 = 0, j2 = 0; j2 < this->line && j1 < this->row - 1; j1++, j2++)
            {
                if (j1 == lineIN - 1)
                {
                    j2++;
                }
                if (j2 >= this->line)
                {
                    break;
                }
                temp.matrix[i1][j1] = this->matrix[i2][j2];
            }
        }
        return temp;
    }

    // 行列式
    int determinant()
    {
        if (this->row == 1)
        {
            return this->matrix[0][0];
        }
        int ans = 0;
        for (int i = 0; i < this->row; i++)
        {
            ans += son(i + 1, 1).determinant() * ((i % 2 == 0) ? 1 : -1) * this->matrix[i][0];
        }
        return ans;
    }

    // 伴随
    Matrix adjoint()
    {
        if (this->isPhalanx())
        {
            Matrix temp(this->row, this->line);
            for (int i = 0; i < this->row; i++)
            {
                for (int j = 0; j < this->line; j++)
                {
                    temp.matrix[i][j] = this->son(i + 1, j + 1).determinant() * (((i + j) % 2 == 0) ? 1 : -1);
                }
            }
            return temp;
        }
        else
        {
            cout << "非法的伴随\n";
            Matrix temp;
            return temp;
        }
    }

private:
    bool isMatrix(const vector<vector<double>> &temp)
    {
        for (auto i : temp)
        {
            if (i.size() != temp[0].size())
            {
                return false;
            }
        }
        return true;
    }
    unsigned int row;
    unsigned int line;
    vector<vector<double>> matrix;
};