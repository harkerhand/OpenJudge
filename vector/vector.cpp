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
    cout << matrixC;
    cout << matrixC.determinant() << endl;
    cout << matrixC.adjoint();

    return 0;
}