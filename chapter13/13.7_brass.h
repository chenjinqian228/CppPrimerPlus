// brass.h -- 银行账户类
#ifndef BRASS_H_
#define BRASS_H_

#include <string>

// Brass 账户类
class Brass {
private:
    std::string fullName;        // 账户持有人全名
    long acctNum;                // 账号
    double balance;              // 当前余额
public:
    // 构造函数,初始化账户信息
    Brass(const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
    // 存款
    void Deposit(double amt);
    // 取款
    virtual void Withdraw(double amt);
    // 获取余额
    double Balance() const;
    // 显示账户信息
    virtual void ViewAcct() const;
    // 虚析构函数
    virtual ~Brass() {}
};

// Brass Plus 账户类
class BrassPlus : public Brass {
private:
    double maxLoan;              // 信用额度
    double rate;                 // 利率
    double owesBank;            // 当前贷款金额
public:
    // 构造函数,初始化账户信息和信用额度
    BrassPlus(const std::string & s = "Nullbody", long an = -1,
              double bal = 0.0, double ml = 500, double r = 0.11125);
    // 复制构造函数,使用已有账户创建新账户
    BrassPlus(const Brass & ba, double ml = 500, double r = 0.11125);
    // 显示账户信息
    virtual void ViewAcct() const;
    // 取款
    virtual void Withdraw(double amt);
    // 设置最大贷款额度
    void ResetMax(double m) { maxLoan = m; }
    // 设置利率
    void ResetRate(double r) { rate = r; }
    // 重置当前贷款金额为0
    void ResetOwes() { owesBank = 0; }
};

#endif
