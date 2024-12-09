// brass.cpp -- 银行账户类方法
#include <iostream>
#include "13.7_brass.h"
using std::cout;
using std::endl;
using std::string;

// 格式化相关
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format, precis);

// Brass 类方法
Brass::Brass(const string & s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

void Brass::Deposit(double amt)
{
    if (amt < 0)
        cout << "不允许负数存款; "
             << "存款已取消.\n";
    else
        balance += amt;
}

void Brass::Withdraw(double amt)
{
    // 设置 ###.## 格式
    format initialState = setFormat();
    precis prec= cout.precision(2);

    if (amt < 0)
        cout << "取款金额必须为正数; "
             << "取款已取消.\n";
    else if (amt <= balance)
        balance -= amt;
    else
        cout << "取款金额 $" << amt
             << " 超过您的余额.\n"
             << "取款已取消.\n";
    restore(initialState,prec);
}

double Brass::Balance() const
{
    return balance;
}

void Brass::ViewAcct() const
{
    // 设置 ###.## 格式
    format initialState = setFormat();
    precis prec= cout.precision(2);
    cout << "客户: " << fullName << endl;
    cout << "账号: " << acctNum << endl;
    cout << "余额: $" << balance << endl;
    restore(initialState,prec);
}

// BrassPlus 类方法
BrassPlus::BrassPlus(const string & s, long an, double bal,
           double ml, double r) : Brass(s, an, bal)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r)
           : Brass(ba)   // 使用隐式复制构造函数
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

// 重新定义 ViewAcct() 的工作方式
void BrassPlus::ViewAcct() const
{
    // 设置 ###.## 格式
    format initialState = setFormat();
    precis prec= cout.precision(2);
    Brass::ViewAcct();   // 显示基类部分
    cout << "最大贷款额度: $" << maxLoan << endl;
    cout << "欠银行金额: $" << owesBank << endl;
    cout.precision(3);    // ###.### 格式
    cout << "贷款利率: " << 100 * rate << "%\n";
    restore(initialState,prec);
}

// 重新定义 Withdraw() 的工作方式
void BrassPlus::Withdraw(double amt)
{
    // 设置 ###.## 格式
    format initialState = setFormat();
    precis prec= cout.precision(2);

    double bal = Balance();
    if (amt <= bal)
        Brass::Withdraw(amt);
    else if ( amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "银行垫款: $" << advance << endl;
        cout << "手续费: $" << advance * rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    }
    else
        cout << "超出信用额度. 交易已取消.\n";
    restore(initialState,prec);
}

format setFormat()
{
    // 设置 ###.## 格式
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}