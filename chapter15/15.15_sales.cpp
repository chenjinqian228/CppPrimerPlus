// sales.cpp -- Sales类的实现
#include "15.14_sales.h"
using std::string;

// bad_index类的构造函数,接收一个索引值和错误信息字符串
Sales::bad_index::bad_index(int ix, const string & s)
    : std::logic_error(s), bi(ix)  // 初始化基类和成员变量
{
}

// Sales类的构造函数,初始化年份和月度销售额数组
Sales::Sales(int yy)
{
    year = yy;
    for (int i = 0; i < MONTHS; ++i)
        gross[i] = 0;  // 将所有月份销售额初始化为0
}

// Sales类的构造函数,使用数组初始化月度销售额
Sales::Sales(int yy, const double * gr, int n)
{
    year = yy;
    int lim = (n < MONTHS) ? n : MONTHS;  // 取较小值作为复制长度
    int i;
    for (i = 0; i < lim; ++i)
        gross[i] = gr[i];  // 复制数组元素
    // 对于i>n且i<MONTHS的情况,将剩余月份销售额设为0
    for (; i < MONTHS; ++i)
        gross[i] = 0;
}

// 重载[]运算符的const版本,用于读取销售额
double Sales::operator[](int i) const
{
    if(i < 0 || i >= MONTHS)
        throw bad_index(i);  // 索引越界则抛出异常
    return gross[i];
}

// 重载[]运算符的非const版本,用于修改销售额
double & Sales::operator[](int i)
{
    if(i < 0 || i >= MONTHS)
        throw bad_index(i);  // 索引越界则抛出异常
    return gross[i];
}

// LabeledSales的nbad_index类构造函数
LabeledSales::nbad_index::nbad_index(const string & lb, int ix,
           const string & s ) : Sales::bad_index(ix, s)
{
    lbl = lb;  // 设置标签
}

// LabeledSales类的构造函数
LabeledSales::LabeledSales(const string & lb, int yy)
         : Sales(yy)  // 调用基类构造函数
{
    label = lb;
}

// LabeledSales类的构造函数,使用数组初始化
LabeledSales::LabeledSales(const string & lb, int yy,
                          const double * gr, int n)
        : Sales(yy, gr, n)  // 调用基类构造函数
{
    label = lb;
}

// 重载[]运算符的const版本
double LabeledSales::operator[](int i) const
{
    if(i < 0 || i >= MONTHS)
        throw nbad_index(Label(), i);  // 抛出带标签的异常
    return Sales::operator[](i);  // 调用基类的运算符
}

// 重载[]运算符的非const版本
double & LabeledSales::operator[](int i)
{
    if(i < 0 || i >= MONTHS)
        throw nbad_index(Label(), i);  // 抛出带标签的异常
    return Sales::operator[](i);  // 调用基类的运算符
}
