// bondini.cpp -- 使用转义序列演示程序
#include <iostream>
int main()
{
    using namespace std;
    cout << "\a操作 \"HyperHype\" 现已激活！\n";
    cout << "请输入特工代码：________\b\b\b\b\b\b\b\b";
    long code;
    cin >> code;
    cout << "\a你输入的代码是 " << code << "...\n";
    cout << "\a代码验证通过！执行23号计划！\n";
    return 0;
}
