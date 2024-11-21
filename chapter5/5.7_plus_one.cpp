// plus_one.cpp -- 递增运算符示例
#include <iostream>     // 包含输入输出流头文件
int main()
{
    using std::cout;    // 使用标准输出对象
    int a = 20;        // 初始化变量 a 为 20
    int b = 20;        // 初始化变量 b 为 20

    // 显示 a 和 b 的初始值
    cout << "a    = " << a << ":    b = " << b << "\n";

    // 演示后置递增(a++)和前置递增(++b)的区别
    cout << "a++  = " << a++ << ":  ++b = " << ++b << "\n";

    // 显示递增后的值
    cout << "a    = " << a << ":    b = " << b << "\n";
    return 0;
}
