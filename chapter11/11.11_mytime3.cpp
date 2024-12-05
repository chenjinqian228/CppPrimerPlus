// mytime3.cpp -- Time类方法的实现
#include "11.10_mytime3.h"

// 默认构造函数：初始化小时和分钟为0
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

// 添加分钟的方法
void Time::AddMin(int m)
{
    minutes += m;                // 加上新的分钟数
    hours += minutes / 60;       // 将溢出的分钟数转换为小时
    minutes %= 60;              // 保留不足一小时的分钟数
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

// 重载加法运算符：两个Time对象相加
Time Time::operator+(const Time & t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;           // 先加分钟
    sum.hours = hours + t.hours + sum.minutes / 60;  // 加小时并处理分钟溢出
    sum.minutes %= 60;                          // 确保分钟在0-59范围内
    return sum;
}

// 重载减法运算符：两个Time对象相减
Time Time::operator-(const Time & t) const
{
    Time diff;
    int tot1, tot2;
    tot1 = t.minutes + 60 * t.hours;    // 将第一个时间转换为分钟
    tot2 = minutes + 60 * hours;        // 将第二个时间转换为分钟
    diff.minutes = (tot2 - tot1) % 60;  // 计算剩余分钟
    diff.hours = (tot2 - tot1) / 60;    // 计算小时数
    return diff;
}

// 重载乘法运算符：Time对象乘以一个数
Time Time::operator*(double mult) const
{
    Time result;
    long totalminutes = hours * 60 * mult + minutes * mult;  // 先转换为分钟后再乘
    result.hours = totalminutes / 60;    // 计算小时数
    result.minutes = totalminutes % 60;   // 计算剩余分钟
    return result;
}

// 重载输出运算符：格式化输出Time对象
std::ostream & operator<<(std::ostream & os, const Time & t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}
