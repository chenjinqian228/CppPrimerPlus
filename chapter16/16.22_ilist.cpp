// ilist.cpp -- 演示 initializer_list 的使用（C++11特性）
#include <iostream>
#include <initializer_list>

// 计算初始化列表中所有数字的和
double sum(std::initializer_list<double> il);
// 计算初始化列表中所有数字的平均值
double average(const std::initializer_list<double> & ril);

int main()
{
    using std::cout;
    
    // 测试用例1：直接使用花括号创建临时初始化列表
    cout << "列表1: 总和 = " << sum({2,3,4})
         << ", 平均值 = " << average({2,3,4}) << '\n';
    
    // 测试用例2：创建具名初始化列表并使用
    std::initializer_list<double> dl = {1.1, 2.2, 3.3, 4.4, 5.5};
    cout << "列表2: 总和 = " << sum(dl)
         << ", 平均值 = " << average(dl) << '\n';
    
    // 测试用例3：重新赋值初始化列表
    dl = {16.0, 25.0, 36.0, 40.0, 64.0};
    cout << "列表3: 总和 = " << sum(dl)
         << ", 平均值 = " << average(dl) << '\n';
    
    return 0;
}

// 求和函数实现
double sum(std::initializer_list<double> il)
{
    double tot = 0;  // 累加器
    // 使用迭代器遍历初始化列表
    for (auto p = il.begin(); p != il.end(); p++)
        tot += *p;   // 累加每个元素
    return tot;
}

// 求平均值函数实现
double average(const std::initializer_list<double> & ril)
{
    double tot = 0;      // 总和
    int n = ril.size();  // 元素个数
    double ave = 0.0;    // 平均值
    if (n > 0)          // 确保列表非空
    {
        // 使用迭代器遍历初始化列表
        for (auto p = ril.begin(); p != ril.end(); p++)
            tot += *p;   // 累加每个元素
        ave = tot / n;   // 计算平均值
    }
    return ave;
}
