// twofile2.cpp -- 具有内部链接和外部链接的变量演示
#include <iostream>
extern int tom;         // tom 在其他地方定义
static int dick = 10;   // 覆盖外部的 dick 变量
int harry = 200;        // 外部变量定义，
                       // 与 twofile1 中的 harry 不冲突

void remote_access()
{
    using namespace std;
    cout << "remote_access() 函数报告以下地址：\n";
    cout << &tom << " = &tom, " << &dick << " = &dick, ";
    cout << &harry << " = &harry\n";
}
