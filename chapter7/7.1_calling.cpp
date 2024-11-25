// calling.cpp -- 函数的定义、原型声明和调用示例
#include <iostream>

void simple();    // 函数原型声明

int main()
{
    using namespace std;
    cout << "main()函数将要调用simple()函数：\n";
    simple();     // 调用函数
    cout << "main()函数已完成调用simple()函数。\n";
    // cin.get();
    return 0;
}

// 函数定义
void simple()
{
    using namespace std;
    cout << "我只是一个简单的函数。\n";
}
