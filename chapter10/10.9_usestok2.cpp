// usestock2.cpp -- 使用 Stock 类
// 与 stock20.cpp 一起编译
#include <iostream>
#include "10.7_stock20.h"
#include "10.8_stock20.cpp"

const int STKS = 4;

int main()
{
    // 创建一个已初始化对象的数组
    Stock stocks[STKS] = {
        Stock("纳米科技", 12, 20.0),
        Stock("博福对象", 200, 2.0),
        Stock("巨石方尖", 130, 3.25),
        Stock("飞跃企业", 60, 6.5)
    };

    std::cout << "股票持仓情况：\n";
    int st;
    for (st = 0; st < STKS; st++)
        stocks[st].show();

    // 指针指向第一个元素
    const Stock * top = &stocks[0];
    for (st = 1; st < STKS; st++)
        top = &top->topval(stocks[st]);

    // 现在 top 指向最有价值的股票
    std::cout << "\n最有价值的持仓：\n";
    top->show();

    return 0;
}
