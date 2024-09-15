<<<<<<< HEAD:NOIOJ/02_奇数单增序列.cpp
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int l;
    cin >> l;
    vector<int> aa;
    for (int i = 1; i <= l; i++)
    {
        int a;
        cin >> a;
        if (a % 2 == 1)
        {
            aa.push_back(a);
        }
    }
    sort(aa.begin(), aa.end());
    for (int i = 0; i + 1 < aa.size(); i++)
    {
        cout << aa[i] << ",";
    }
    cout << aa[aa.size() - 1];
}

int main()
{
    solve();
=======
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
}

int main()
{
    return 0;
>>>>>>> d57db79a3dc4a81d211f23028416d8d597b0f86d:NOIOJ/03_Rectangular_segmentation.cpp
}