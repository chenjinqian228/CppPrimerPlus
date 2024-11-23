// ifelse.cpp -- 演示 if else 语句的使用
#include <iostream>
int main()
{
    char ch;
    
    std::cout << "请输入一些文字，我将重复这些内容。\n";
    std::cin.get(ch);
    while (ch != '.')  // 当输入不是句号时继续循环
    {
        if (ch == '\n')
            std::cout << ch;      // 如果是换行符就直接输出
        else
            std::cout << ch;    // 否则输出该字符的下一个字符
        std::cin.get(ch);
    }
    // 尝试用 ch + 1 替代 ++ch 会产生有趣的效果
    std::cout << "\n请原谅这个小小的混乱。\n";
    // std::cin.get();    // 暂停程序
    // std::cin.get();    // 暂停程序
    return 0;
}
