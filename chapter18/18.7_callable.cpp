// callable.cpp -- 可调用类型和模板示例
#include "18.6_somedefs.h"
#include <iostream>

// 将输入值翻倍的函数
double dub(double x) {return 2.0*x;}
// 计算平方的函数
double square(double x) {return x*x;}

int main()
{
    using std::cout;
    using std::endl;

    double y = 1.21;
    cout << "函数指针 dub:\n";
    cout << " " << use_f(y, dub) << endl;
    cout << "函数指针 square:\n";
    cout << " " << use_f(y, square) << endl;
    cout << "函数对象 Fp:\n";
    cout << " " << use_f(y, Fp(5.0)) << endl;
    cout << "函数对象 Fq:\n";
    cout << " " << use_f(y, Fq(5.0)) << endl;
    cout << "Lambda表达式 1:\n";
    cout << " " << use_f(y, [](double u) {return u*u;}) << endl;  // 计算平方的lambda
    cout << "Lambda表达式 2:\n";
    cout << " " << use_f(y, [](double u) {return u+u/2.0;}) << endl;  // 计算1.5倍的lambda
    return 0;
}
