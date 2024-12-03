// usenmsp.cpp -- 命名空间的使用示例
#include <iostream>
#include "9.12_namesp.cpp"

void other(void);    // 其他函数声明
void another(void);  // 另一个函数声明

int main(void)
{
    using debts::Debt;         // 使用 debts 命名空间中的 Debt 类型
    using debts::showDebt;     // 使用 debts 命名空间中的 showDebt 函数
    
    // 创建一个债务记录，包含姓名和金额
    Debt golf = { {"本尼", "高特斯尼夫"}, 120.0 };
    showDebt(golf);            // 显示债务信息
    other();                   // 调用其他函数
    another();                 // 调用另一个函数
    return 0;
}

void other(void)
{
    using std::cout;           // 使用标准输出
    using std::endl;           // 使用换行符
    using namespace debts;     // 使用整个 debts 命名空间
    
    // 创建一个人员记录
    Person dg = {"杜德尔斯", "格利斯特"};
    showPerson(dg);            // 显示人员信息
    cout << endl;
    
    Debt zippy[3];            // 创建债务数组
    int i;
    // 循环获取三笔债务信息
    for (i = 0; i < 3; i++)
        getDebt(zippy[i]);
    
    // 显示所有债务信息    
    for (i = 0; i < 3; i++)
        showDebt(zippy[i]);
    
    // 计算并显示总债务
    cout << "总债务金额: ￥" << sumDebts(zippy, 3) << endl;
    return;
}

void another(void)
{
    using pers::Person;        // 使用 pers 命名空间中的 Person 类型
    // 创建收债人信息
    Person collector = { "米洛", "莱特希夫特" };
    pers::showPerson(collector);  // 使用完全限定名称显示人员信息
    std::cout << std::endl;
}
