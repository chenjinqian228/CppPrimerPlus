// stonewt.cpp -- Stonewt类的方法实现
#include <iostream>
#include "11.16_stonewt.h"
using std::cout;

// 通过磅数构造Stonewt对象
Stonewt::Stonewt(double lbs)
{
    stone = int (lbs) / lbs_per_stn;    // 整数除法，计算完整的石数
    pds_left = int (lbs) % lbs_per_stn + lbs - int(lbs);  // 计算剩余磅数（包括小数部分）
    pounds = lbs;  // 保存总磅数
}

// 通过石数和磅数构造Stonewt对象
Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;  // 保存石数
    pds_left = lbs;  // 保存剩余磅数
    pounds = stn * lbs_per_stn + lbs;  // 计算总磅数
}

Stonewt::Stonewt()          // 默认构造函数，重量设为0
{
    stone = pounds = pds_left = 0;  // 所有值都初始化为0
}

Stonewt::~Stonewt()        // 析构函数
{
    // 不需要做任何事情
}
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
