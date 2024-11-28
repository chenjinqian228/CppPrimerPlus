// inline.cpp -- 使用内联函数的示例
#include <iostream>

// 内联函数定义
// 计算一个数的平方
inline double square(double x) { return x * x; }

int main()
{
    using namespace std;
    double a, b;    // 声明两个双精度浮点数变量
    
    double c = 13.0;    // 初始化变量c为13.0
    
    a = square(5.0);    // 计算5.0的平方
    b = square(4.5 + 7.5);    // 可以传入表达式计算结果的平方
    cout << "a = " << a << ", b = " << b << "\n";    // 输出a和b的值
    cout << "c = " << c;    // 输出c的当前值
    cout << ", c的平方 = " << square(c++) << "\n";    // 计算c的平方，然后c自增
    cout << "现在c的值 = " << c << "\n";    // 显示自增后的c值
    return 0;
}
