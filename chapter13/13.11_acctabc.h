// acctabc.h -- 银行账户类
#ifndef ACCTABC_H_
#define ACCTABC_H_
#include <iostream>
#include <string>

// 抽象基类
class AcctABC
{
private:
    std::string fullName;      // 账户持有人全名
    long acctNum;              // 账号
    double balance;            // 当前余额
protected:
    // 格式化结构体，用于保存并设置输出格式
    struct Formatting {
        std::ios_base::fmtflags flag;    // 格式标志
        std::streamsize pr;               // 精度
    };
    const std::string & FullName() const { return fullName; }
    long AcctNum() const { return acctNum; }
    Formatting SetFormat() const;
    void Restore(Formatting & f) const;
public:
    AcctABC(const std::string & s = "Nullbody", long an = -1,
                double bal = 0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt) = 0;   // 纯虚函数
    double Balance() const { return balance; };
    virtual void ViewAcct() const = 0;       // 纯虚函数
    virtual ~AcctABC() {}
};

// 普通账户类
class Brass : public AcctABC
{
public:
    Brass(const std::string & s = "Nullbody", long an = -1,
                double bal = 0.0) : AcctABC(s, an, bal) { }
    virtual void Withdraw(double amt);
    virtual void ViewAcct() const;
    virtual ~Brass() {}
};

// 高级账户类
class BrassPlus : public AcctABC
{
private:
    double maxLoan;       // 贷款上限
    double rate;          // 贷款利率
    double owesBank;      // 欠银行金额
public:
    BrassPlus(const std::string & s = "Nullbody", long an = -1,
            double bal = 0.0, double ml = 500,
            double r = 0.11125);
    BrassPlus(const Brass & ba, double ml = 500, double r = 0.11125);
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    void ResetMax(double m) { maxLoan = m; }
    void ResetRate(double r) { rate = r; }
    void ResetOwes() { owesBank = 0; }
};

#endif
