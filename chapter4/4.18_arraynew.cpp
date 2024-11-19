// arraynew.cpp -- 使用new运算符操作数组
#include <iostream>
int main()
{
    using namespace std;
    double * p3 = new double [3]; // 为3个double类型数据分配空间
    p3[0] = 0.2;                  // 像数组名一样使用p3
    p3[1] = 0.5;
    p3[2] = 0.8;
    cout << "p3[1]的值是" << p3[1] << ".\n";
    p3 = p3 + 1;                  // 指针向后移动一个元素
    cout << "现在p3[0]的值是" << p3[0] << "，而且";
    cout << "p3[1]的值是" << p3[1] << ".\n";
    p3 = p3 - 1;                  // 指针移回起始位置
    delete [] p3;                 // 释放内存
    return 0;
}
