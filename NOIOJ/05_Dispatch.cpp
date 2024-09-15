#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define ll long long
vector<double> aaa;
const double pi = acos(-1);

bool check(double mid, int people)
{
    double sum = 0;
    int cnt = 0;
    for (int i = 0; i < aaa.size(); i++)
    {
        cnt += aaa[i] / mid;
        if (cnt > people)
            return true;
    }
    return false;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    double maxx = 0;
    for (int i = 0; i < n; i++)
    {
        double x;
        cin >> x;
        x *= x * pi;
        maxx = max(maxx, x);
        aaa.push_back(x);
    }
    double left = 0;
    double right = maxx;
    while (abs(right - left) > 0.00001)
    {
        double mid = (left + right) / 2;
        if (check(mid, m))
            left = mid;
        else
            right = mid;
    }
    cout << fixed << setprecision(3) << left;
}

int main()
{
    solve();
    return 0;
}