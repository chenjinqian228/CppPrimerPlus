// mytime2.h -- 运算符重载后的时间类
#ifndef MYTIME2_H_
#define MYTIME2_H_

class Time  // 时间类
{
private:
    int hours;    // 小时
    int minutes;  // 分钟
public:
    Time();                      // 默认构造函数
    Time(int h, int m = 0);     // 带参数的构造函数，m默认值为0
    void AddMin(int m);         // 添加分钟
    void AddHr(int h);          // 添加小时
    void Reset(int h = 0, int m = 0);  // 重置时间，默认重置为0时0分
    
    // 运算符重载函数
    Time operator+(const Time & t) const;  // 重载加法运算符
    Time operator-(const Time & t) const;  // 重载减法运算符
    Time operator*(double n) const;        // 重载乘法运算符（与实数相乘）
    
    void Show() const;          // 显示时间的函数
};

#endif
