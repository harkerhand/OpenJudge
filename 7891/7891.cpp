#include <iostream>
using namespace std;

double a, b, c, d;

double f(double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}

int main()
{

    cin >> a >> b >> c >> d;
    for (double i = -100; i <= 100; i++)
    {
        double x1 = i, x2 = i + 1;
        if (f(x1) == 0)
        {
            printf("%.2lf ", x1);
        }
        else
        {
            if (f(x1) * f(x2) < 0)
            {
                while (x2 - x1 >= 0.001)
                {
                    double xm = (x1 + x2) / 2;
                    if (f(xm) * f(x1) < 0)
                    {
                        x2 = xm;
                    }
                    else
                    {
                        x1 = xm;
                    }
                }
                printf("%.2lf ", x1);
            }
        }
    }

    return 0;
}