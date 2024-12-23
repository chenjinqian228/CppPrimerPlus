// peeker.cpp -- 一些 istream 输入流方法的演示
#include <iostream>

int main()
{
    using std::cout;    // 使用标准输出
    using std::cin;     // 使用标准输入
    using std::endl;    // 使用标准换行符

// 读取并回显输入，直到遇到 # 字符
    char ch;

    while(cin.get(ch))        // 在遇到文件结束符(EOF)时终止
    {
        if (ch != '#')
            cout << ch;       // 如果不是#号就输出
        else
        {
            cin.putback(ch);  // 将字符重新放回输入流
            break;            // 退出循环
        }
    }

    if (!cin.eof())          // 如果没有到达文件结尾
    {
        cin.get(ch);
        cout << endl << ch << " 是下一个输入字符。\n";
    }
    else
    {
        cout << "已到达文件结尾。\n";
        std::exit(0);        // 退出程序
    }

    while(cin.peek() != '#') // 预览下一个字符（向前查看）
    {
        cin.get(ch);
        cout << ch;
    }
    if (!cin.eof())         // 如果没有到达文件结尾
    {
        cin.get(ch);
        cout << endl << ch << " 是下一个输入字符。\n";
    }
    else
        cout << "已到达文件结尾。\n";

    return 0;
}
