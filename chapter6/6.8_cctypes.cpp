// cctypes.cpp -- 使用 ctype.h 库
#include <iostream>
#include <cctype>          // 字符函数的原型声明
int main()
{
    using namespace std;
    cout << "请输入要分析的文本，输入 @ 符号结束输入。\n";
    
    char ch;               // 用于存储单个字符
    int whitespace = 0;    // 空白字符计数
    int digits = 0;        // 数字计数
    int chars = 0;         // 字母计数
    int punct = 0;         // 标点符号计数
    int others = 0;        // 其他字符计数

    cin.get(ch);          // 获取第一个字符
    while (ch != '@')     // 检查是否遇到结束标记
    {
        if(isalpha(ch))       // 是否是字母？
            chars++;
        else if(isspace(ch))  // 是否是空白字符？
            whitespace++;
        else if(isdigit(ch))  // 是否是数字？
            digits++;
        else if(ispunct(ch))  // 是否是标点符号？
            punct++;
        else
            others++;
        cin.get(ch);          // 获取下一个字符
    }
    cout << chars << " 个字母，"
         << whitespace << " 个空白字符，"
         << digits << " 个数字，"
         << punct << " 个标点符号，"
         << others << " 个其他字符。\n";
    return 0;
}
