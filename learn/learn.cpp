#include <iostream>
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
            if (arr[j] > arr[j + 1])
            {
                swap01(arr + j, arr + j + 1);
                // 数组的变量名可以直接加法表示后面的某一位
            }
        }
    }
}

struct person
{
    // 结构体 自定义数据类型
    // 例子
    string name;
    short age;
    bool sex;
};

void swap02(person *a, person *b) // 交换结构体
{
    person temp = *a;
    *a = *b;
    *b = temp;
}

struct person people[2] = {
    {"boy", 16, 1},
    {"girl", 14, 0}};

int main()
{
    // int *p;
    // 声明一个指针, 指针保存的是地址
    // 声明时 * 表示指针, 引用时 * 表示解引用
    // 例子

    /* int a = 1, b = 2;
    swap01(&a, &b); // & 表示取地址
    cout << "a = " << a << " b = " << b << endl; */

    // const 与 指针
    // const修饰指针, 指向可以改, 值不能改
    // const修饰常量, 指向不可改, 值可以改
    // const也可以两者都修饰
    /* int a = 1, b = 2;
    const int *p1 = &a;
    p1 = &b;
    int *const p2 = &b;
    *p2 = a; */

    // 指针和数组
    // int arr[4] = {1, 2, 3, 4};
    // arr即为首个元素的地址
    // 例1

    /* int arr[4] = {4, 3, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    bubble(arr, len);
    for (int i = 0; i < len; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << " ";
    } */

    // 结构体例子
    /* person harker = {"haerker", 18, 1};
    cout << "name : " << harker.name; */

    // 结构体指针
    // 创建一个函数, 交换两个人的信息
    // 例子
    /* swap02(people, people + 1); // 传入地址 people是数组
    cout << "people[0].name = " << people[0].name << " people[1].name = " << people[1].name << endl;
    // 指针使用 -> 访问结构体中的元素
    cout << "people[0].name = " << people->name << " people[1].name = " << (people + 1)->name << endl; */

    return 0;
}