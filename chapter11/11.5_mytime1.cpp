// mytime1.cpp -- 实现Time类的方法
#include <iostream>
#include "11.4_mytime1.h"

// 默认构造函数：初始化时间为0时0分
Time::Time()
{
    hours = minutes = 0;
}

// 带参数构造函数：根据传入的小时和分钟初始化
Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

// 添加分钟的方法
// 如果分钟数超过60，会自动转换为小时
void Time::AddMin(int m)
{
    minutes += m;                // 添加分钟
    hours += minutes / 60;       // 将超出60分钟的部分转换为小时
    minutes %= 60;              // 保留不足60分钟的部分
}

// 添加小时的方法
void Time::AddHr(int h)
{
    hours += h;
}

// 重置时间的方法
void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

// 重载加法运算符
// 将两个Time对象的时间相加
Time Time::operator+(const Time & t) const
{
    Time sum;                            // 创建一个新的Time对象存储结果
    sum.minutes = minutes + t.minutes;   // 加总分钟数
    sum.hours = hours + t.hours + sum.minutes / 60;  // 加总小时数（包括分钟进位）
    sum.minutes %= 60;                   // 确保分钟数不超过60
    return sum;
}

// 显示时间的方法
void Time::Show() const
{
    std::cout << hours << " 小时, " << minutes << " 分钟";
}
