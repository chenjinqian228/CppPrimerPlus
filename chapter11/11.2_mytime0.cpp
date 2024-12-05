// mytime0.cpp -- Time类方法的实现
#include <iostream>
#include "11.1_mytime0.h"

// 默认构造函数
Time::Time()
{
    hours = minutes = 0;    // 将小时和分钟都初始化为0
}

// 带参数的构造函数
Time::Time(int h, int m)
{
    hours = h;             // 设置小时
    minutes = m;           // 设置分钟
}

// 添加分钟
void Time::AddMin(int m)
{
    minutes += m;          // 添加分钟
    hours += minutes / 60; // 计算额外的小时数
    minutes %= 60;         // 保留不足一小时的分钟数
}

// 添加小时
void Time::AddHr(int h)
{
    hours += h;           // 直接添加小时数
}

// 重置时间
void Time::Reset(int h, int m)
{
    hours = h;            // 设置新的小时数
    minutes = m;          // 设置新的分钟数
}

// 计算两个Time对象的和
Time Time::Sum(const Time & t) const
{
    Time sum;                            // 创建新的Time对象存储结果
    sum.minutes = minutes + t.minutes;   // 加总分钟数
    sum.hours = hours + t.hours + sum.minutes / 60;  // 加总小时数（包括分钟进位）
    sum.minutes %= 60;                   // 确保分钟数在0-59范围内
    return sum;                          // 返回结果
}

// 显示时间
void Time::Show() const
{
    std::cout << hours << " 小时, " << minutes << " 分钟";
}
