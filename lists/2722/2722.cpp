#include<iostream>
using namespace std;



int main(){
    int a, b[101];
    cin >> a;
    for(int i = 0; i < a; i++){
        cin >> b[i];
    }
    int ans = 0;

    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            for(int k = 0; k < a; k++){
                if(i == j || i == k || j == k){
                    continue;
                }else{
                    if(b[i] == b[j] + b[k]){
                        ans++;
                        j = a;
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}