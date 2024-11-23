// if.cpp -- 使用if语句
#include <iostream>
int main()
{
    using std::cin;      // 使用声明
    using std::cout;
    char ch;            // 用于存储字符
    int spaces = 0;     // 空格计数器
    int total = 0;      // 总字符计数器
    cin.get(ch);       // 获取一个字符
    while (ch != '.')   // 当遇到句号时结束
    {
        if (ch == ' ')  // 检查字符是否为空格
            ++spaces;   // 如果是空格，空格计数加1
        ++total;        // 总是执行：字符总数加1
        cin.get(ch);    // 获取下一个字符
    }
    cout << spaces << " 个空格, " << total;
    cout << " 个字符在句子中\n";
    return 0;
}
