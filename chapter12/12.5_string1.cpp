// string1.cpp -- String类方法的实现
#include <cstring>                // 引入string.h
#include "12.4_string1.h"        // 包含了<iostream>
using std::cin;
using std::cout;

// 初始化静态类成员
int String::num_strings = 0;

// 静态方法
int String::HowMany() 
{
    return num_strings;
}

// 类方法实现
String::String(const char * s)     // 从C风格字符串构造String
{
    len = std::strlen(s);         // 设置大小
    str = new char[len + 1];      // 分配存储空间
    std::strcpy(str, s);          // 初始化指针
    num_strings++;                // 更新对象计数
}

String::String()                   // 默认构造函数
{
    len = 4;
    str = new char[1];
    str[0] = '\0';                // 默认字符串
    num_strings++;
}

String::String(const String & st)  // 拷贝构造函数
{
    num_strings++;                // 处理静态成员更新
    len = st.len;                // 复制长度
    str = new char [len + 1];    // 分配空间
    std::strcpy(str, st.str);    // 将字符串复制到新位置
}

String::~String()                 // 析构函数
{
    --num_strings;               // 减少对象计数
    delete [] str;               // 释放动态分配的内存
}

// 重载运算符方法实现    
String & String::operator=(const String & st)  // 赋值运算符（String版本）
{
    if (this == &st)             // 自我赋值检查
        return *this;
    delete [] str;               // 释放旧内存
    len = st.len;
    str = new char[len + 1];     // 分配新内存
    std::strcpy(str, st.str);    // 复制字符串
    return *this;
}

String & String::operator=(const char * s)     // 赋值运算符（C字符串版本）
{
    delete [] str;               // 释放旧内存
    len = std::strlen(s);
    str = new char[len + 1];     // 分配新内存
    std::strcpy(str, s);         // 复制字符串
    return *this;
}

// 非const String的读写字符访问
char & String::operator[](int i)
{
    return str[i];
}

// const String的只读字符访问
const char & String::operator[](int i) const
{
    return str[i];
}

// 重载运算符友元函数实现
bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
    return st2 < st1;            // 通过已实现的<运算符来实现
}

bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

// 简单的String输出
ostream & operator<<(ostream & os, const String & st)
{
    os << st.str;
    return os; 
}

// 快速的String输入
istream & operator>>(istream & is, String & st)
{
    char temp[String::CINLIM];    // 临时字符数组
    is.get(temp, String::CINLIM); // 读取输入
    if (is)
        st = temp;                // 如果输入成功，使用赋值运算符
    while (is && is.get() != '\n')// 清除多余的输入
        continue;
    return is; 
}
