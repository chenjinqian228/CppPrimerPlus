// strgfun.cpp -- 带有字符串参数的函数
#include <iostream>
// 函数声明：计算字符在字符串中出现的次数
unsigned int c_in_str(const char * str, char ch);

int main()
{
    using namespace std;
    // 定义并初始化一个字符数组
    char mmm[15] = "minimum";    // 在数组中存储字符串
    // 一些系统需要在 char 前加上 static 关键字
    // 才能启用数组初始化
    
    char *wail = "ululate";      // wail 指向字符串
    
    // 计算 'm' 在 mmm 中出现的次数
    unsigned int ms = c_in_str(mmm, 'm');
    // 计算 'u' 在 wail 中出现的次数
    unsigned int us = c_in_str(wail, 'u');
    // 输出结果
    cout << ms << " 个字符 m 在 " << mmm << " 中" << endl;
    cout << us << " 个字符 u 在 " << wail << " 中" << endl;
    return 0;
}

// 这个函数用于计算字符 ch 在字符串 str 中出现的次数
unsigned int c_in_str(const char * str, char ch)
{
    // 初始化计数器
    unsigned int count = 0;
    
    while (*str)                 // 当 *str 不是 '\0' 时继续循环
    {
        if (*str == ch)          // 如果当前字符等于要查找的字符
            count++;             // 计数器加1
        str++;                   // 移动指针到下一个字符
    }
    return count;                // 返回字符出现的总次数
}
