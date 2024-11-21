// textin1.cpp -- 使用while循环读取字符
#include <iostream>
int main()
{
    using namespace std;
    
    char ch;           // 存储输入的字符
    int count = 0;     // 计数器初始化为0
    
    cout << "请输入一些字符，输入#号结束：\n";
    cin >> ch;         // 获取一个字符
    while (ch != '#')  // 测试字符是否为#
    {
        cout << ch;    // 显示该字符（回显）
        ++count;       // 字符计数加1
        cin >> ch;     // 获取下一个字符
    }
    cout << endl << "共读取了 " << count << " 个字符\n";
    return 0;
}
