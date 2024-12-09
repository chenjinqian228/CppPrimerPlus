// stringbad.cpp -- StringBad类的方法实现
#include <cstring>      // 包含字符串处理函数
#include "12.1_stringBad.h"

// 初始化静态类成员
int StringBad::num_strings = 0;

// 类方法实现
// 从C风格字符串构造StringBad对象
StringBad::StringBad(const char * s)
{
    len = std::strlen(s);             // 设置字符串长度
    str = new char[len + 1];         // 分配内存空间（+1是为了存储结尾的空字符）
    std::strcpy(str, s);             // 复制字符串内容
    num_strings++;                    // 增加对象计数
    std::cout << num_strings << ": \"" << str
              << "\" 对象被创建\n";    // 信息提示
}

StringBad::StringBad()               // 默认构造函数
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");         // 默认字符串
    num_strings++;
    std::cout << num_strings << ": \"" << str
              << "\" 默认对象被创建\n";  // 信息提示
}

StringBad::~StringBad()              // 必需的析构函数
{
    std::cout << "\"" << str << "\" 对象被删除, ";    // 信息提示
    --num_strings;                    // 必需的操作：减少对象计数
    std::cout << "还剩 " << num_strings << " 个\n";    // 信息提示
    delete [] str;                    // 必需的操作：释放动态分配的内存
}

// 重载输出运算符
std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
    os << st.str;
    return os;
}
