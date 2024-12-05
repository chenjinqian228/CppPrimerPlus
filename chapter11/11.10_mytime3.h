// mytime3.h -- 带有友元函数的时间类
#ifndef MYTIME3_H_
#define MYTIME3_H_
#include <iostream>

class Time  // 时间类
{
private:
    int hours;    // 小时
    int minutes;  // 分钟
public:
    Time();                     // 默认构造函数
    Time(int h, int m = 0);     // 带参数的构造函数，分钟默认值为0
    void AddMin(int m);         // 添加分钟
    void AddHr(int h);          // 添加小时
    void Reset(int h = 0, int m = 0);  // 重置时间，默认值都为0
    
    // 运算符重载函数
    Time operator+(const Time & t) const;  // 加法运算符
    Time operator-(const Time & t) const;  // 减法运算符
    Time operator*(double n) const;        // 乘法运算符（Time * double）
    
    // 友元函数
    friend Time operator*(double m, const Time & t)  
        { return t * m; }    // 内联定义，用于实现 double * Time
    
    // 友元函数：输出流运算符重载
    friend std::ostream & operator<<(std::ostream & os, const Time & t);
};

#endif
