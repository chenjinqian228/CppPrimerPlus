// twofile1.cpp -- 具有外部链接和内部链接的变量演示
#include <iostream>      // 需要与 twofile2.cpp 一起编译
#include "9.8_twofile2.cpp"
int tom = 3;            // 外部变量定义
int dick = 30;          // 外部变量定义
static int harry = 300; // 静态变量，内部链接



// 函数原型声明
void remote_access();



int main()
{
    using namespace std;
    cout << "main() 函数报告以下地址：\n";
    cout << &tom << " = &tom, " << &dick << " = &dick, ";
    cout << &harry << " = &harry\n";
    remote_access();
    return 0;
}
