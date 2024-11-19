// pointer.cpp -- 我们的第一个指针变量
#include <iostream>
int main()
{
    using namespace std;
    int updates = 6;           // 声明一个变量
    int* p_updates;          // 声明一个指向整数的指针
    p_updates = &updates;     // 将整数的地址赋给指针

    // 用两种方式表示值
    cout << "值: updates = " << updates;
    cout << ", *p_updates = " << *p_updates << endl;

    // 用两种方式表示地址
    cout << "地址: &updates = " << &updates;
    cout << ", p_updates = " << p_updates << endl;

    // 使用指针改变值
    *p_updates = *p_updates + 1;
    cout << "现在 updates = " << updates << endl;
    return 0;
}
