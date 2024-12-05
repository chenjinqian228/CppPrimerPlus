// mytime0.h -- Time类（运算符重载前的版本）
#ifndef MYTIME0_H_    // 防止头文件重复包含
#define MYTIME0_H_

class Time
{
private:
    int hours;        // 小时数
    int minutes;      // 分钟数
public:
    Time();          // 默认构造函数
    Time(int h, int m = 0);    // 带参数的构造函数，分钟参数默认为0
    void AddMin(int m);        // 添加分钟
    void AddHr(int h);         // 添加小时
    void Reset(int h = 0, int m = 0);    // 重置时间，默认重置为0时0分
    Time Sum(const Time & t) const;       // 将两个Time对象相加
    void Show() const;                    // 显示时间
};
#endif
