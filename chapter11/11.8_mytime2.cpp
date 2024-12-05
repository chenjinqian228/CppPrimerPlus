// mytime2.cpp -- Time类方法的实现
#include <iostream>
#include "11.7_mytime2.h"

// 默认构造函数：初始化为0时0分
Time::Time()
{
    hours = minutes = 0;
}

// 带参数的构造函数：设置指定的小时和分钟
Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

// 添加分钟，自动处理进位
void Time::AddMin(int m)
{
    minutes += m;                // 加上输入的分钟数
    hours += minutes / 60;       // 分钟数超过60的部分转换为小时
    minutes %= 60;              // 保留不足60分钟的部分
}

// 添加小时
void Time::AddHr(int h)
{
    hours += h;
}

// 重置时间为指定的小时和分钟
void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

// 重载加法运算符：两个时间相加
Time Time::operator+(const Time & t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;           // 先把分钟加起来
    sum.hours = hours + t.hours + sum.minutes / 60;  // 小时数加上分钟进位的小时
    sum.minutes %= 60;                          // 处理分钟进位后的余数
    return sum;
}

// 重载减法运算符：两个时间相减
Time Time::operator-(const Time & t) const
{
    Time diff;
    int tot1, tot2;
    tot1 = t.minutes + 60 * t.hours;    // 把第一个时间转换为分钟
    tot2 = minutes + 60 * hours;        // 把第二个时间转换为分钟
    diff.minutes = (tot2 - tot1) % 60;  // 计算差值的分钟部分
    diff.hours = (tot2 - tot1) / 60;    // 计算差值的小时部分
    return diff;
}

// 重载乘法运算符：时间乘以一个数字
Time Time::operator*(double mult) const
{
    Time result;
    long totalminutes = hours * 60 * mult + minutes * mult;  // 先转换为分钟后再乘
    result.hours = totalminutes / 60;    // 计算小时部分
    result.minutes = totalminutes % 60;  // 计算分钟部分
    return result;
}

// 显示时间
void Time::Show() const
{
    std::cout << hours << " 小时, " << minutes << " 分钟";
}
