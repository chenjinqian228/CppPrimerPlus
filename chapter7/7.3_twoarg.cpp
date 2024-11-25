// twoarg.cpp -- 一个带有2个参数的函数示例
#include <iostream>
using namespace std;
void n_chars(char, int);    // 函数原型声明

int main()
{
    int times;              // 定义重复次数
    char ch;               // 定义要显示的字符
    
    cout << "请输入一个字符：";
    cin >> ch;
    while (ch != 'q')      // 输入q时退出
    {
        cout << "请输入一个整数：";
        cin >> times;
        n_chars(ch, times); // 调用带两个参数的函数
        cout << "\n请输入另一个字符或按"
             << " q键退出：";
        cin >> ch;
    }
    cout << "times的值为" << times << "。\n";
    cout << "再见！\n";
    return 0;
}

void n_chars(char c, int n)  // 显示字符c共n次
{
    while (n-- > 0)         // 循环直到n变为0
        cout << c;
}
