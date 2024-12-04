// stock00.cpp -- Stock类的实现
#include <iostream>
#include "10.4_stock10.h"

Stock::Stock()
{
    std::cout << "默认构造函数\n";
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const std::string &co, long n, double pr)
{
    std::cout << "构造函数\n";
    company = co;
    if (n < 0)
    {
        std::cout << "持股数量不能为负数。 "
                  << "持股数量已设置为0。\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}
Stock::~Stock()
{
    std::cout << "析构函数:"<<company;
}

// 购买股票
void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "购买的股票数量不能为负数。 "
                  << "交易已取消。\n";
    }
    else
    {
        shares += num;     // 更新持股数量
        share_val = price; // 更新股价
        set_tot();         // 重新计算总值
    }
}

// 卖出股票
void Stock::sell(long num, double price)
{
    if (num < 0)
    {
        std::cout << "卖出的股票数量不能为负数。 "
                  << "交易已取消。\n";
    }
    else if (num > shares)
    {
        std::cout << "卖出数量不能超过持有数量！ "
                  << "交易已取消。\n";
    }
    else
    {
        shares -= num;     // 减少持股数量
        share_val = price; // 更新股价
        set_tot();         // 重新计算总值
    }
}

// 更新股票价格
void Stock::update(double price)
{
    share_val = price; // 更新股价
    set_tot();         // 重新计算总值
}

// 显示股票信息
void Stock::show()
{
    using std::cout;
    using std::ios_base;
    // 设置格式为 #.###（3位小数）
    ios_base::fmtflags orig =
        cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);

    cout << "公司：" << company
         << "  股数：" << shares << '\n';
    cout << "  每股价格：$" << share_val;
    // 设置格式为 #.##（2位小数）
    cout.precision(2);
    cout << "  总价值：$" << total_val << '\n';

    // 恢复原始格式设置
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}
