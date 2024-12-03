// external.cpp -- 外部变量示例
// 需要与 support.cpp 一起编译
#include <iostream>
#include "9.6_support.cpp"
using namespace std;

// 外部变量
double warming = 0.3;    // warming 变量定义

// 函数原型声明
void update(double dt);  // 更新函数
void local();           // 局部变量函数

int main()              // 使用全局变量
{
    cout << "全球变暖现在是 " << warming << " 度。\n";
    update(0.1);        // 调用函数来改变 warming 值
    cout << "全球变暖现在是 " << warming << " 度。\n";
    local();            // 调用使用局部 warming 变量的函数
    cout << "全球变暖现在是 " << warming << " 度。\n";
    return 0;
}
