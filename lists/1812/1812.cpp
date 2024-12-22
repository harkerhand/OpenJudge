#include<iostream>
using namespace std;


void mySort(int *a){//冒泡排序
    int t;
    if(a[0] > a[1]){
        t = a[0];
        a[0] = a [1];
        a[1] = t;
    }
    if(a[1] > a[2]){
        t = a[1];
        a[1] = a [2];
        a[2] = t;
    }
    if(a[0] > a[1]){
        t = a[0];
        a[0] = a [1];
        a[1] = t;
    }
}

bool compare(int *a, int b[100000][3], int mm){//传入被比较值和数据库,mm作计数器减少性能开支
    for(int i = 0; i < mm; i++){
        if(a[0] == b[i][0] && a[1] == b[i][1] && a[2] == b[i][2]){
            return true;
        }
    }
    return false;
}

int main(){
    int a;
    cin >> a;
    int mem[100000][3] = {0, 0, 0};//记忆数组
    int mm = 0;
    for(int i = 2; i <= a; i ++){
        for(int j = 2; j < i; j++){
            for(int m = 2; m < i; m++){
                for(int n = 2; n < i; n++){
                    if(i * i * i == j * j * j + m * m * m + n * n * n){
                        int c[3] = {j, m, n};
                        mySort(c);//对符合条件的数组排序
                        if(!compare(c, mem, mm)){
                            mem[mm][0] = c[0];
                            mem[mm][1] = c[1];
                            mem[mm][2] = c[2];
                            mm++;
                            cout << "Cube = "<< i << "," << " Triple = (" << j << "," << m << "," << n << ")" << endl;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

