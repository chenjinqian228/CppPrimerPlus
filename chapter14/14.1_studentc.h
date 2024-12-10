#ifndef STUDENTC_H_
#define STUDENTC_H_
#include <iostream>
#include <string>
#include <valarray>

// Student类定义了一个学生对象，包含学生姓名和分数数组
class Student {
private:
    typedef std::valarray<double> ArrayDb;  // 定义ArrayDb类型为double数组
    std::string name;           // 学生姓名
    ArrayDb scores;             // 学生分数数组
    // 分数输出的私有方法
    std::ostream & arr_out(std::ostream & os) const;
public:
    // 构造函数:
    Student() : name("无名学生"), scores() {}  // 默认构造函数
    explicit Student(const std::string & s)    // explicit防止隐式转换,只能显式调用构造函数
        : name(s), scores() {}
    explicit Student(int n) : name("无名"), scores(n) {}  //explicit防止隐式转换 仅接受分数数量的构造函数
    Student(const std::string & s, int n)      // 接受名字和分数数量的构造函数
        : name(s), scores(n) {}
    Student(const std::string & s, const ArrayDb & a)  // 接受名字和分数数组的构造函数
        : name(s), scores(a) {}
    Student(const char * str, const double * pd, int n)  // 接受C风格字符串和分数数组的构造函数
        : name(str), scores(pd,n) {}
    ~Student() {}  // 析构函数
    // 成员函数:
    double Average() const;                // 计算平均分
    const std::string & Name() const;      // 获取姓名
    double & operator[](int i);            // 重载[]运算符(可修改)
    double operator[](int i) const;        // 重载[]运算符(只读)
    // 友元函数:
    // 输入
    friend std::istream & operator>>(std::istream & is,
                                   Student & stu);  // 输入一个单词作为名字
    friend std::istream & getline(std::istream & is,
                                 Student & stu);    // 输入一行作为名字
    // 输出
    friend std::ostream & operator<<(std::ostream & os,
                                   const Student & stu);  // 输出学生信息
};

#endif
