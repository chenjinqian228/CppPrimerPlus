// 银行账户类方法
#include <iostream>
#include "13.11_acctabc.h"
using std::cout;
using std::ios_base;
using std::endl;
using std::string;

// 抽象基类
AcctABC::AcctABC(const std::string & s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

void AcctABC::Deposit(double amt)
{
    if (amt < 0)
        cout << "不允许负数存款; "
             << "存款已取消.\n";
    else
        balance += amt;
}

void AcctABC::Withdraw(double amt)
{
    balance -= amt;
}

// 受保护的方法
AcctABC::Formatting AcctABC::SetFormat() const
{
    // 设置 ###.## 格式
    Formatting f;
    f.flag  = cout.setf(ios_base::fixed,ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}

void AcctABC::Restore(Formatting & f )const
{
    cout.setf(f.flag,ios_base::floatfield);
    cout.precision(f.pr);
}

// Brass类方法
void Brass::Withdraw(double amt)
{
    if (amt < 0)
        cout << "取款金额必须为正数; "
             << "取款已取消.\n";
    else if (amt <= Balance())
        AcctABC::Withdraw(amt);
    else
        cout << "取款金额 $" << amt
             << " 超过您的余额.\n"
             << "取款已取消.\n";
}

void Brass::ViewAcct() const
{
    Formatting f = SetFormat();
    cout << "Brass客户: " << FullName() << endl;
    cout << "账号: " << AcctNum() << endl;
    cout << "余额: $" << Balance() << endl;
    Restore(f);
}

// BrassPlus类方法
BrassPlus::BrassPlus(const std::string & s, long an, double bal,
           double ml, double r) : AcctABC(s, an, bal)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r; 
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r)
           : AcctABC(ba)     // 使用隐式复制构造函数
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct() const
{
    Formatting f = SetFormat();

    cout << "BrassPlus客户: " << FullName() << endl;
    cout << "账号: " << AcctNum() << endl;
    cout << "余额: $" << Balance() << endl;
    cout << "最大贷款额: $" << maxLoan << endl;
    cout << "欠银行: $" << owesBank << endl;
    cout << "贷款利率: " << 100 * rate << "%\n";
   Restore(f);
}

void BrassPlus::Withdraw(double amt)
{
    Formatting f = SetFormat();

    double bal = Balance();
    if (amt <= bal)
        AcctABC::Withdraw(amt);
    else if ( amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "银行垫款: $" << advance << endl;
        cout << "财务费用: $" << advance * rate << endl;
        Deposit(advance);
        AcctABC::Withdraw(amt);
    }
    else
        cout << "超出信用额度。交易已取消.\n";
    Restore(f);
}
