#include<iostream>
using namespace std;

int main()
{
    int a[105][105],m,n;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> a[n + 1 - i][j];
        }
    }
    
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            cout << a[j][i] << " ";
        }
        cout << endl;
    }


    return 0;
}