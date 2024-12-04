// stock20.h -- 增强版本
#ifndef STOCK20_H_
#define STOCK20_H_
#include <string>

class Stock
{
private:
    std::string company;        // 公司名称
    int shares;                 // 持有的股票数量
    double share_val;          // 每股价格
    double total_val;          // 股票总价值
    void set_tot() { total_val = shares * share_val; }  // 计算总值

public:
    Stock();                    // 默认构造函数
    Stock(const std::string & co, long n = 0, double pr = 0.0);  // 带参数的构造函数
    ~Stock();                   // 析构函数（不执行任何操作）
    void buy(long num, double price);    // 购买股票
    void sell(long num, double price);   // 卖出股票
    void update(double price);           // 更新股票价格
    void show() const;                   // 显示股票信息
    const Stock & topval(const Stock & s) const;  // 比较两支股票
};

#endif
