// stock20.cpp -- 增强版本
#include <iostream>
#include "10.7_stock20.h"

// 构造函数
Stock::Stock() // 默认构造函数
{
    company = "无名";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const std::string &co, long n, double pr)
{
    company = co;
    if (n < 0)
    {
        std::cout << "股票数量不能为负数； "
                  << company << " 股票数量设置为0。\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

// 类析构函数
Stock::~Stock() // 简单的类析构函数
{
}

// 其他方法
void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "购买的股票数量不能为负数。 "
                  << "交易已取消。\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    if (num < 0)
    {
        std::cout << "卖出的股票数量不能为负数。 "
                  << "交易已取消。\n";
    }
    else if (num > shares)
    {
        std::cout << "您不能卖出超过持有数量的股票！ "
                  << "交易已取消。\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show() const
{
    using std::cout;
    using std::ios_base;
    // 设置格式为 #.###
    ios_base::fmtflags orig =
        cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);

    cout << "公司：" << company
         << "  持股数：" << shares << '\n'
         << "  每股价格：$" << share_val;
    // 设置格式为 #.##
    cout.precision(2);
    cout << "  总价值：$" << total_val << '\n';

    // 恢复原始格式
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

const Stock &Stock::topval(const Stock &s) const
{
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}
