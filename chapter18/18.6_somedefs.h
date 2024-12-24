// somedefs.h
#include <iostream>
#include <functional>
// 模板函数use_f:
// T: 值类型 
// F: 函数对象类型
// v: 输入值
// f: 函数对象
// template <typename T, typename F>
// T use_f(T v, F f)
template <typename T>
T use_f(T v, std::function<T(T)> f)
{
    static int count = 0;  // 静态计数器,记录函数调用次数
    count++;
    std::cout << " use_f count = " << count 
              << ", &count = " << &count << std::endl;  // 输出计数和计数器地址
    return f(v);  // 调用函数对象f处理输入值v
}

// 函数对象类Fp:实现乘法运算
class Fp
{
private:
    double z_;  // 乘数因子
public:
    Fp(double z = 1.0) : z_(z) {}  // 构造函数,默认乘数为1.0
    double operator()(double p) { return z_ * p; }  // 重载()运算符实现乘法
};

// 函数对象类Fq:实现加法运算
class Fq
{
private:
    double z_;  // 加数
public:
    Fq(double z = 1.0) : z_(z) {}  // 构造函数,默认加数为1.0
    double operator()(double q) { return z_ + q; }  // 重载()运算符实现加法
};
