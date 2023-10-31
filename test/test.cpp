#include <iostream>
using namespace std;

int main()
{
    int c = 5;
    c++;
    c = c++ + ++c;
    cout << c;
}