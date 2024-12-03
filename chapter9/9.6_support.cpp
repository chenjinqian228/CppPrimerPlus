// support.cpp -- 使用外部变量
// 需要与 external.cpp 一起编译
#include <iostream>
extern double warming;    // 使用来自其他文件的 warming 变量声明

// 函数原型声明
void update(double dt);
void local();

using std::cout;

void update(double dt)    // 修改全局变量
{
    extern double warming;    // 可选的重复声明
    warming += dt;           // 使用全局变量 warming
    cout << "正在更新全球变暖数据为 " << warming;
    cout << " 度。\n";
}

void local()               // 使用局部变量
{
    double warming = 0.8;   // 新的局部变量，会隐藏外部变量
    
    cout << "局部变暖数据 = " << warming << " 度。\n";
    // 使用作用域解析运算符
    // 访问全局变量
    cout << "但全局变暖数据 = " << ::warming;
    cout << " 度。\n";
}
