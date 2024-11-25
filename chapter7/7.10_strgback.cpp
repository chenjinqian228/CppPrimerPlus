// strgback.cpp -- 一个返回字符指针的函数
#include <iostream>
char * buildstr(char c, int n);      // 函数原型

int main()
{
    using namespace std;
    int times;          // 用于存储用户输入的次数
    char ch;           // 用于存储用户输入的字符
    
    cout << "请输入一个字符: ";
    cin >> ch;
    cout << "请输入一个整数: ";
    cin >> times;
    char *ps = buildstr(ch, times);   // 创建第一个字符串
    cout << ps << endl;
    delete [] ps;                     // 释放内存
    ps = buildstr('+', 20);          // 重复使用指针，创建新字符串
    cout << ps << "-完成-" << ps << endl;
    delete [] ps;                     // 释放内存
    return 0;
}

// 构建一个由n个字符c组成的字符串
char * buildstr(char c, int n)
{
    char * pstr = new char[n + 1];    // 动态分配内存，额外的1个字节用于存储结束符
    pstr[n] = '\0';                   // 在字符串末尾添加终止符
    while (n-- > 0)
        pstr[n] = c;                  // 填充字符串的其余部分
    return pstr;                      // 返回字符串指针
}
