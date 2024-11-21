// textin3.cpp -- 读取字符直到文件末尾
#include <iostream>
int main()
{
    using namespace std;
    char ch;           // 存储读取的字符
    int count = 0;     // 字符计数器

    cin.get(ch);       // 尝试读取一个字符
    while (cin.fail() == false)   // 测试是否到达文件末尾(EOF)
    {
        cout << ch;    // 显示读取的字符
        ++count;       // 计数器加1
        cin.get(ch);   // 尝试读取下一个字符
    }
    cout << endl << "共读取了 " << count << " 个字符\n";
    return 0;
}
