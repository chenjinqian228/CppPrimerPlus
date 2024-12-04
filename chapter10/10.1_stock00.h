// stock00.h -- 股票类接口
// 版本 00
#ifndef STOCK00_H
#define STOCK00_H

#include <string>

class Stock // 类声明
{
private:
    std::string company;                               // 公司名称
    long shares;                                       // 持股数量
    double share_val;                                  // 每股价格
    double total_val;                                  // 总价值
    void set_tot() { total_val = shares * share_val; } // 计算总值
public:

    // 获取股票信息（参数：公司名称，股数，价格）
    void acquire(const std::string &co, long n, double pr);

    // 购买股票（参数：购买数量，价格）
    void buy(long num, double price);

    // 卖出股票（参数：卖出数量，价格）
    void sell(long num, double price);

    // 更新股票价格（参数：新价格）
    void update(double price);

    // 显示股票信息
    void show();
}; // 注意末尾的分号

#endif
