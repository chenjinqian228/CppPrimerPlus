// precise.cpp -- 设置数值精度
#include <iostream>

int main()
{
    using std::cout;

    // 定义两个浮点数变量表示价格
    float price1 = 20.40;
    float price2 = 1.9 + 8.0 / 9.0;  // 计算结果约为2.79

    // 未设置精度时的输出
    cout << "\"Furry Friends\" is $" << price1 << "!\n";  // 输出"毛绒朋友"的价格
    cout << "\"Fiery Fiends\" is $" << price2 << "!\n";   // 输出"火焰恶魔"的价格

    // 设置输出精度为2位
    cout.precision(3);
    // 设置精度后的输出
    cout << "\"Furry Friends\" is $" << price1 << "!\n";  // 使用新的精度输出
    cout << "\"Fiery Fiends\" is $" << price2 << "!\n";   // 使用新的精度输出

    return 0;
}
