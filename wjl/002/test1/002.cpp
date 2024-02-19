#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

set<int> ans;
map<int, vector<int>> in;
void find(int i = 1)
{
    int len = in[i].size();
    ans.insert(i);
    for (int j = len - 2; j >= 0; --j)
        find(in[i][j]);
}

int main()
{

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int Ci;
        cin >> Ci;
        in[i].resize(Ci + 1);
        in[i][Ci] = i;
        while (Ci--)
        {
            cin >> in[i][Ci];
        }
    }
    find();
    cout << ans.size() << endl;
}