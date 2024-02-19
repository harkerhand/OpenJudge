#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

set<int> ans;
int in[5005][5005] = {0};
void find(int i = 1)
{
    for (int j = 0; in[i][j] != 0; ++j)
    {
        if (i == in[i][j])
            ans.insert(i);
        else
            find(in[i][j]);
    }
}

int main()
{

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int Ci;
        cin >> Ci;
        in[i][Ci] = i;
        while (Ci--)
        {
            cin >> in[i][Ci];
        }
    }
    find();
    cout << ans.size() << endl;
    return 0;
}