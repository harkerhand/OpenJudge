#include <iostream>
#include <vector>
#include "Matrix.h"
using namespace std;

int main()
{
    vector<vector<double>> a = {{3, 5, 7}, {12, 13, 6}, {6, 3, 153}};
    vector<vector<double>> b = {{4, 8, 10}, {6, 13, 16}, {3, 5, 7}};
    Matrix matrixA(a);
    Matrix matrixB(b);
    Matrix matrixC = matrixA + matrixB;
    cout << matrixC.son(2, 2);
    cout << matrixC.son(2, 2).determinant() << endl;
    vector<vector<double>> c = {{1, 2}, {3, 4}};
    Matrix matrixD(c);
    cout << matrixD.adjoint() << endl;

    return 0;
}