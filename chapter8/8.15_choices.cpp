// choices.cpp -- 模板选择示例
#include <iostream>

// 通用函数模板声明
template<typename T>    // 或者使用 template <typename T>
T lesser(T a, T b)   // #1 - 通用模板版本
{
    return a < b ? a : b;    // 返回两个值中的较小值
}

// 专门用于整数的重载函数
int lesser(int a, int b)    // #2 - 特化版本
{
    // 将负数转换为正数后比较
    a = a < 0 ? -a : a;     // 如果 a 为负数则取其绝对值
    b = b < 0 ? -b : b;     // 如果 b 为负数则取其绝对值
    return a < b ? a : b;    // 返回绝对值较小的数
}

int main()
{
    using namespace std;
    int m = 20;           // 整数变量
    int n = -30;         // 负整数变量
    double x = 15.5;     // 双精度浮点数变量
    double y = 25.9;     // 双精度浮点数变量

    // 不同的函数调用方式
    cout << lesser(m, n) << endl;        // 使用 #2 特化版本（处理整数）
    cout << lesser(x, y) << endl;        // 使用 #1 模板版本（处理 double 类型）
    cout << lesser<>(m, n) << endl;      // 强制使用 #1 模板版本处理整数
    cout << lesser<int>(x, y) << endl;   // 强制使用 #1 模板版本，并将参数转换为整数
    
    return 0;
}
