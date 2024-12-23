// showpt.cpp -- 设置精度，显示尾随小数点
#include <iostream>

int main()
{
    using std::cout;
    using std::ios_base;    // 用于格式化输出的基类

    // 定义两个浮点数价格变量
    float price1 = 20.40;
    float price2 = 1.9 + 8.0 / 9.0;  // 计算结果约为2.79

    // 设置显示尾随小数点
    cout.setf(ios_base::showpoint);
    // 输出价格（带尾随小数点）
    cout << "\"Furry Friends\" is $" << price1 << "!\n";  // 输出"毛绒朋友"的价格
    cout << "\"Fiery Fiends\" is $" << price2 << "!\n";   // 输出"火焰恶魔"的价格

    // 设置输出精度为2位
    cout.precision(2);
    // 使用新的精度再次输出价格
    cout << "\"Furry Friends\" is $" << price1 << "!\n";
    cout << "\"Fiery Fiends\" is $" << price2 << "!\n";

    return 0;
}
