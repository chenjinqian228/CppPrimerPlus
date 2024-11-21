// dowhile.cpp -- 出口条件循环
#include <iostream>
int main()
{
    using namespace std;
    int n;    // 用于存储用户输入的数字
    
    cout << "请在1-10的范围内输入数字来猜测";
    cout << "我最喜欢的数字\n";
    do
    {
        cin >> n;        // 执行循环体：获取用户输入
    } while (n != 7);    // 然后测试条件：检查是否为7
    cout << "没错，7就是我最喜欢的数字。\n";
    return 0;
}
