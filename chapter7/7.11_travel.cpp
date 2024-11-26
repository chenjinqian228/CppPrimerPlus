// travel.cpp -- 演示结构体与函数的使用
#include <iostream>
// 定义时间结构体
struct travel_time
{
    int hours;    // 小时
    int mins;     // 分钟
};
const int Mins_per_hr = 60;    // 定义每小时的分钟数

// 函数原型声明
travel_time sum(travel_time t1, travel_time t2);    // 计算两个时间的和
void show_time(travel_time t);                      // 显示时间

int main()
{
    using namespace std;
    travel_time day1 = {5, 45};      // 第一天：5小时45分钟
    travel_time day2 = {4, 55};      // 第二天：4小时55分钟
    
    // 计算两天的总时间
    travel_time trip = sum(day1, day2);
    cout << "两天总计: ";
    show_time(trip);
    
    // 添加第三天的时间并计算三天总和
    travel_time day3= {4, 32};       // 第三天：4小时32分钟
    cout << "三天总计: ";
    show_time(sum(trip, day3));
    
    return 0;
}

// 计算两个时间的和的函数实现
travel_time sum(travel_time t1, travel_time t2)
{
    travel_time total;
    
    // 处理分钟，超过60分钟的部分转换为小时
    total.mins = (t1.mins + t2.mins) % Mins_per_hr;
    // 计算小时，包括分钟进位的小时
    total.hours = t1.hours + t2.hours +
                 (t1.mins + t2.mins) / Mins_per_hr;
    return total;
}

// 显示时间的函数实现
void show_time(travel_time t)
{
    using namespace std;
    cout << t.hours << " 小时, "
         << t.mins << " 分钟\n";
}
