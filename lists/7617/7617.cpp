#include <iostream>
#include <algorithm>
using namespace std;

void swap01(int *a, int *b) // 传入地址
{
    int temp = *a; // *解引用
    *a = *b;
    *b = temp;
}

void bubble(int *arr, int len) // 对数组进行冒泡排序
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] < arr[j + 1]) // 此处修改为倒序
            {
                swap01(arr + j, arr + j + 1);
                // 数组的变量名可以直接加法表示后面的某一位
            }
        }
    }
}

int main()
{
    int input;
    cin >> input;
    int arr[input];
    for (int i = 0; i < input; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + input);
    int k;
    cin >> k;
    for (int i = input - 1; i > input - k - 1; i--)
    {
        cout << arr[i] << endl;
    }

    return 0;
}