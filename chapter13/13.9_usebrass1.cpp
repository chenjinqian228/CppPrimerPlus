// usebrass1.cpp -- 测试银行账户类
#include <iostream>
#include "13.7_brass.h"
#include "13.8_brass.cpp"

int main()
{
    using std::cout;
    using std::endl;

    Brass Piggy("波塞洛特·皮格", 381299, 4000.00);
    BrassPlus Hoggy("霍雷肖·霍格", 382288, 3000.00);
    
    Piggy.ViewAcct();
    cout << endl;
    Hoggy.ViewAcct();
    cout << endl;
    
    cout << "向霍格账户存入1000元:\n";
    Hoggy.Deposit(1000.00);
    cout << "新余额: " << Hoggy.Balance() << "元" << endl;
    
    cout << "从皮格账户取出4200元:\n";
    Piggy.Withdraw(4200.00);
    cout << "皮格账户余额: " << Piggy.Balance() << "元" << endl;
    
    cout << "从霍格账户取出4200元:\n";
    Hoggy.Withdraw(4200.00);
    Hoggy.ViewAcct();

    return 0;
}
