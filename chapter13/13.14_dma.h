#ifndef DMA_H_
#define DMA_H_
#include <string>

// 使用DMA的基类
// baseDMA是一个基类,使用动态内存分配(DMA)
// 包含两个成员:label(字符指针,用于动态分配内存存储标签)和rating(评级)
class baseDMA {
private:
    char * label;     // 动态分配的标签字符串
    int rating;       // 评级
public:
    baseDMA(const char * l = "null", int r = 0);    // 构造函数
    baseDMA(const baseDMA & rs);                    // 拷贝构造函数
    virtual ~baseDMA();                             // 虚析构函数
    baseDMA & operator=(const baseDMA & rs);        // 赋值运算符重载
    friend std::ostream & operator<<(std::ostream & os, const baseDMA & rs); // 友元输出运算符
};

// 不使用DMA的派生类
// lacksDMA继承自baseDMA,但不使用动态内存分配
// 新增成员color使用固定长度数组
class lacksDMA : public baseDMA {
private:
    enum { COL_LEN = 40 };    // 颜色字符串的固定长度
    char color[COL_LEN];      // 固定长度的颜色数组
public:
    lacksDMA(const char * c = "blank", const char * l = "null", int r = 0); // 构造函数
    lacksDMA(const char * c, const baseDMA & rs);                           // 使用基类对象的构造函数
    friend std::ostream & operator<<(std::ostream & os, const lacksDMA & rs); // 友元输出运算符
};

// 使用DMA的派生类
// hasDMA继承自baseDMA,并使用动态内存分配
// 新增成员style使用动态内存分配
class hasDMA : public baseDMA {
private:
    char * style;     // 动态分配的样式字符串
public:
    hasDMA(const char * s = "none", const char * l = "null", int r = 0); // 构造函数
    hasDMA(const char * s, const baseDMA & rs);                          // 使用基类对象的构造函数
    hasDMA(const hasDMA & hs);                                          // 拷贝构造函数
    ~hasDMA();                                                          // 析构函数
    hasDMA & operator=(const hasDMA & rs);                             // 赋值运算符重载
    friend std::ostream & operator<<(std::ostream & os, const hasDMA & rs); // 友元输出运算符
};

#endif
