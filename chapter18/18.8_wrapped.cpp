// wrapped.cpp -- 使用函数包装器作为参数
#include "18.6_somedefs.h"
#include <iostream>
#include <functional>

// 两倍函数：返回输入值的2倍
double dub(double x) { return 2.0*x; }
// 平方函数：返回输入值的平方
double square(double x) { return x*x; }

int main()
{
    using std::cout;
    using std::endl;
    using std::function;

    double y = 1.21;
    // 创建不同类型的函数包装器
    // function<double(double)> ef1 = dub;     // 包装普通函数dub
    // function<double(double)> ef2 = square;  // 包装普通函数square
    // function<double(double)> ef3 = Fp(10.0);// 包装函数对象Fp
    // function<double(double)> ef4 = Fq(10.0);// 包装函数对象Fq
    // function<double(double)> ef5 = [](double u) { return u*u; };      // 包装lambda表达式1
    // function<double(double)> ef6 = [](double u) { return u+u/2.0; };  // 包装lambda表达式2

    // // 输出各种函数的结果
    // cout << "函数指针 dub:\n";
    // cout << " " << use_f(y, ef1) << endl;
    // cout << "函数指针 square:\n";
    // cout << " " << use_f(y, ef2) << endl;
    // cout << "函数对象 Fp:\n";
    // cout << " " << use_f(y, ef3) << endl;
    // cout << "函数对象 Fq:\n";
    // cout << " " << use_f(y, ef4) << endl;
    // cout << "Lambda表达式 1:\n";
    // cout << " " << use_f(y, ef5) << endl;
    // cout << "Lambda表达式 2:\n";
    // cout << " " << use_f(y, ef6) << endl;

    cout << " " << use_f<double>(y,dub) << endl;
    cout << " " << use_f<double>(y,square) << endl;
    cout << " " << use_f<double>(y,Fp(10.0)) << endl;
    cout << " " << use_f<double>(y,Fq(10.0)) << endl;
    cout << " " << use_f<double>(y,[](double u) { return u*u; }) << endl;
    cout << " " << use_f<double>(y,[](double u) { return u+u/2.0; }) << endl;
    return 0;
}
