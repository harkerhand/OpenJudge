#include<iostream>
using namespace std;

int main()
{
    int n,m,k,A[105][105],B[105][105];
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> A[i][j];
        }
    }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= k;j++){
            cin >> B[i][j];
        }
    }
    int l;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= k;j++){
            l = 0;
            for(int h = 1;h <= m;h++){
                l += A[i][h] * B[h][j];
            }
            cout << l << ' ';
        }
        cout << endl;
    }
    return 0;
}