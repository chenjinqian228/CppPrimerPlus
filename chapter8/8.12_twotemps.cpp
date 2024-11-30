// twotemps.cpp -- 使用重载的函数模板
#include <iostream>
template <typename T>     // 原始模板
void Swap(T &a, T &b);

template <typename T>     // 新模板
void Swap(T *a, T *b, int n);

void Show(int a[]);
const int Lim = 8;
int main()
{
    using namespace std;
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "使用编译器生成的整数交换器：\n";
    Swap(i,j);              // 匹配原始模板
    cout << "交换后 i, j = " << i << ", " << j << ".\n";

    int d1[Lim] = {0,7,0,4,1,7,7,6};
    int d2[Lim] = {0,7,2,0,1,9,6,9};
    cout << "原始数组：\n";
    Show(d1);
    Show(d2);
    Swap(d1,d2,Lim);        // 匹配新模板
    cout << "交换后的数组：\n";
    Show(d1);
    Show(d2);
    return 0;
}

template <typename T>
void Swap(T &a, T &b)    // 交换单个值的模板函数
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
void Swap(T *a, T *b, int n)    // 交换数组的模板函数
{
    T temp;
    for (int i = 0; i < n; i++)
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

void Show(int a[])    // 显示数组内容
{
    using namespace std;
    cout << a[0] << a[1] << "/";
    cout << a[2] << a[3] << "/";
    for (int i = 4; i < Lim; i++)
        cout << a[i];
    cout << endl;
}
