// or.cpp -- 使用逻辑OR运算符
#include <iostream>
int main()
{
    using namespace std;
    cout << "本程序可能会重新格式化您的硬盘\n"
         << "并删除所有数据。\n"
         << "您确定要继续吗？<y/n> ";
    char ch;
    cin >> ch;
    if (ch == 'y' || ch == 'Y')         // y 或 Y
        cout << "您已经被警告过了！\a\a\a\n";
    else if (ch == 'n' || ch == 'N')    // n 或 N
        cout << "明智的选择...再见\n";
    else
        cout << "这不是 y 或 n！看来您 "
             << "不会按照\n指示操作，所以 "
             << "我还是要格式化您的硬盘。\a\a\a\n";
    return 0;
}
