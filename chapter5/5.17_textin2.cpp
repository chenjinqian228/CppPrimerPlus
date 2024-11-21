// textin2.cpp -- 使用 cin.get(char) 函数读取字符
#include <iostream>
int main()
{
    using namespace std;
    char ch;           // 用于存储输入的字符
    int count = 0;     // 字符计数器初始化为0
    
    cout << "请输入一些字符，输入#号结束：\n";
    
    cin.get(ch);       // 使用 cin.get(ch) 函数读取一个字符
    while (ch != '#')  // 当字符不是#时继续循环
    {
        cout << ch;    // 显示该字符
        ++count;       // 计数器加1
        cin.get(ch);   // 再次使用 cin.get() 读取下一个字符
    }
    cout << endl << "共读取了 " << count << " 个字符\n";
    return 0;
}
