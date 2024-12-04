// usestock0.cpp -- 客户端程序
// 需要与 stock00.cpp 一起编译
#include <iostream>
#include "10.1_stock00.h"
#include "10.2_stock00.cpp"
int main()
{
    // 创建一个股票对象
    Stock fluffy_the_cat;
    
    // 初始化股票信息：公司名为"NanoSmart"，持有20股，每股12.50
    // fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
    fluffy_the_cat.show();  // 显示当前股票信息
    
    // 购买15股，每股价格18.125
    fluffy_the_cat.buy(15, 18.125);
    fluffy_the_cat.show();  // 显示当前股票信息
    
    // 尝试卖出400股，每股价格20.00（这会失败，因为持股数量不足）
    fluffy_the_cat.sell(400, 20.00);
    fluffy_the_cat.show();  // 显示当前股票信息
    
    // 购买300000股，每股价格40.125
    fluffy_the_cat.buy(300000, 40.125);
    fluffy_the_cat.show();  // 显示当前股票信息
    
    // 卖出300000股，每股价格0.125
    fluffy_the_cat.sell(300000, 0.125);
    fluffy_the_cat.show();  // 显示当前股票信息
    
    return 0;
}
