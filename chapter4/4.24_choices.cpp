// choices.cpp -- 数组的多种变体
#include <iostream>
#include <vector>    // STL C++98
#include <array>     // C++11

int main()
{
    using namespace std;

    // C语言和原始C++风格
    double a1[4] = {1.2, 2.4, 3.6, 4.8};

    // C++98 STL风格
    vector<double> a2(4);    // 创建一个包含4个元素的vector
    // C98中没有简单的初始化方式
    a2[0] = 1.0/3.0;
    a2[1] = 1.0/5.0;
    a2[2] = 1.0/7.0;
    a2[3] = 1.0/9.0;

    // C++11 -- 创建并初始化array对象
    array<double, 4> a3 = {3.14, 2.72, 1.62, 1.41};
    array<double, 4> a4;
    a4 = a3;    // 对于相同大小的array对象，可以直接赋值

    // 使用数组表示法
    cout << "a1[2]: " << a1[2] << " 位于 " << &a1[2] << endl;
    cout << "a2[2]: " << a2[2] << " 位于 " << &a2[2] << endl;
    cout << "a3[2]: " << a3[2] << " 位于 " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " 位于 " << &a4[2] << endl;

    // 错误操作
    a1[-2] = 20.2;  // 危险：访问越界
    cout << "a1[-2]: " << a1[-2] << " 位于 " << &a1[-2] << endl;
    cout << "a3[2]: " << a3[2] << " 位于 " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " 位于 " << &a4[2] << endl;

    return 0;
}
