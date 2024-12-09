#ifndef STRING1_H_
#define STRING1_H_
#include <iostream>
using std::ostream;
using std::istream;

class String
{
private:
    char * str;                  // 字符串指针
    int len;                     // 字符串长度
    static int num_strings;      // 对象计数器
    static const int CINLIM = 80;// 输入限制长度
public:
    // 构造函数和其他方法
    String(const char * s);      // 构造函数（接受C风格字符串）
    String();                    // 默认构造函数
    String(const String &);      // 拷贝构造函数
    ~String();                   // 析构函数
    int length () const { return len; }  // 获取长度方法

    // 重载运算符方法
    String & operator=(const String &);   // 赋值运算符（String类型）
    String & operator=(const char *);     // 赋值运算符（C风格字符串）
    char & operator[](int i);            // 下标运算符
    const char & operator[](int i) const; // 常量对象的下标运算符

    // 重载运算符友元函数
    friend bool operator>(const String &st, const String &st2);    // 大于运算符
    friend bool operator<(const String &st1, const String &st2);   // 小于运算符
    friend bool operator==(const String &st, const String &st2);   // 相等运算符
    friend ostream & operator<<(ostream & os, const String & st);  // 输出流运算符
    friend istream & operator>>(istream & is, String & st);        // 输入流运算符

    // 静态函数
    static int HowMany();        // 返回当前对象数量
};
#endif
