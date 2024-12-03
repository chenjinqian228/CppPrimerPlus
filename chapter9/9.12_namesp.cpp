// namesp.cpp -- 命名空间的实现文件
#include <iostream>
#include "9.11_namesp.h"

// pers 命名空间：实现与人员信息相关的函数
namespace pers
{
    using std::cout;    // 使用标准输出
    using std::cin;     // 使用标准输入

    // 获取人员信息的函数实现
    void getPerson(Person & rp)    // rp 是对 Person 对象的引用
    {
        cout << "请输入名字: ";     // 原文：Enter first name:
        cin >> rp.fname;           // 读取名字
        cout << "请输入姓氏: ";     // 原文：Enter last name:
        cin >> rp.lname;           // 读取姓氏
    }

    // 显示人员信息的函数实现
    void showPerson(const Person & rp)    // 使用常量引用，防止修改原数据
    {
        std::cout << rp.lname << "，" << rp.fname;    // 使用中文逗号
    }
}

// debts 命名空间：实现与债务信息相关的函数
namespace debts
{
    // 获取债务信息的函数实现
    void getDebt(Debt & rd)    // rd 是对 Debt 对象的引用
    {
        getPerson(rd.name);                // 首先获取债务人的信息
        std::cout << "请输入债务金额: ";     // 原文：Enter debt:
        std::cin >> rd.amount;             // 读取债务金额
    }
    
    // 显示债务信息的函数实现
    void showDebt(const Debt & rd)    // 使用常量引用，防止修改原数据
    {
        showPerson(rd.name);                          // 显示债务人信息
        std::cout << ": ￥" << rd.amount << std::endl; // 使用人民币符号替换美元符号
    }
    
    // 计算债务总额的函数实现
    double sumDebts(const Debt ar[], int n)    // 接收债务数组和数组大小
    {
        double total = 0;                      // 初始化总额为0
        for (int i = 0; i < n; i++)           // 遍历债务数组
            total += ar[i].amount;             // 累加每个债务金额
        return total;                          // 返回总额
    }
}
