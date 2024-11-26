// arfupt.cpp -- 函数指针数组示例
#include <iostream>
// 不同的表示方法，相同的函数签名
const double * f1(const double ar[], int n);
const double * f2(const double [], int);
const double * f3(const double *, int);

int main()
{
    using namespace std;
    double av[3] = {1112.3, 1542.6, 2227.9};

    // 声明一个指向函数的指针
    const double *(*p1)(const double *, int) = f1;
    auto p2 = f2;  // C++11 自动类型推导
    // C++11 之前可以使用以下代码
    // const double *(*p2)(const double *, int) = f2;
    cout << "使用函数指针：\n";
    cout << " 地址  值\n";
    cout << (*p1)(av,3) << ": " << *(*p1)(av,3) << endl;
    cout << p2(av,3) << ": " << *p2(av,3) << endl;

    // pa 是一个指针数组
    // auto 不能用于列表初始化
    const double *(*pa[3])(const double *, int) = {f1,f2,f3};
    // 但可以用于初始化单个值
    // pb 是指向 pa 第一个元素的指针
    auto pb = pa;
    // C++11 之前可以使用以下代码
    // const double *(**pb)(const double *, int) = pa;
    cout << "\n使用函数指针数组：\n";
    cout << " 地址  值\n";
    for (int i = 0; i < 3; i++)
        cout << pa[i](av,3) << ": " << *pa[i](av,3) << endl;
    cout << "\n使用指向函数指针的指针：\n";
    cout << " 地址  值\n";
    for (int i = 0; i < 3; i++)
        cout << pb[i](av,3) << ": " << *pb[i](av,3) << endl;

    return 0;
}

// 一些简单的函数实现

// f1 返回原始数组的起始位置
const double * f1(const double * ar, int n)
{
    return ar;
}

// f2 返回原始数组的第二个元素位置
const double * f2(const double ar[], int n)
{
    return ar+1;
}

// f3 返回原始数组的第三个元素位置
const double * f3(const double ar[], int n)
{
    return ar+2;
}
