// stone1.cpp -- 用户自定义转换函数
// 需要与stonewt1.cpp一起编译
#include <iostream>
#include "11.19_stonewt1.h"
#include "11.20_stonewt1.cpp"

int main()
{
    using std::cout;
    Stonewt poppins(9,2.8);      // 9石2.8磅
    double p_wt = poppins;       // 隐式转换
    cout << "转换为double => ";
    cout << "Poppins: " << p_wt << " 磅.\n";
    cout << "转换为int => ";
    cout << "Poppins: " << int(poppins) << " 磅.\n";
    return 0;
}
