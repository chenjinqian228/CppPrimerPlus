// stonewt1.cpp -- Stonewt类的方法实现和转换函数
#include <iostream>
using std::cout;
#include "11.19_stonewt1.h"

// 通过磅值构造Stonewt对象
Stonewt::Stonewt(double lbs)
{
    stone = int (lbs) / Lbs_per_stn;    // 整数除法
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

// 通过石数和磅值构造Stonewt对象
Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()          // 默认构造函数，重量 = 0
{
    stone = pounds = pds_left = 0;
}
Stonewt::~Stonewt(){}
// 以石为单位显示重量
void Stonewt::show_stn() const
{
    cout << stone << " 石, " << pds_left << " 磅\n";
}

// 以磅为单位显示重量
void Stonewt::show_lbs() const
{
    cout << pounds << " 磅\n"; 
}

// 类型转换函数
Stonewt::operator int() const
{
    return int (pounds + 0.5);    // 四舍五入到最接近的整数
}

Stonewt::operator double() const
{
    return pounds;
}
