// strngbad.h -- 有缺陷的字符串类定义
#include <iostream>
#ifndef STRNGBAD_H_    // 防止头文件重复包含
#define STRNGBAD_H_

class StringBad {
private:
    char * str;                // 指向字符串的指针
    int len;                   // 字符串长度
    static int num_strings;    // 对象计数器（所有对象共享）
public:
    StringBad(const char * s); // 构造函数（接受C风格字符串参数）
    StringBad();              // 默认构造函数
    ~StringBad();             // 析构函数
    // 友元函数
    friend std::ostream & operator<<(std::ostream & os, const StringBad & st);  // 重载输出运算符
};

#endif
