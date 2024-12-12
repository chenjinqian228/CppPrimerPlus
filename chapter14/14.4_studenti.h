// studenti.h -- 使用私有继承定义Student类
#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <valarray>
#include <string>

class Student : private std::string, private std::valarray<double>
{
private:
    typedef std::valarray<double> ArrayDb;
    // 用于成绩输出的私有方法
    std::ostream & arr_out(std::ostream & os) const;

public:
    Student() : std::string("空学生"), ArrayDb() {}
    explicit Student(const std::string & s)
        : std::string(s), ArrayDb() {}
    explicit Student(int n) : std::string("无名"), ArrayDb(n) {}
    Student(const std::string & s, int n)
        : std::string(s), ArrayDb(n) {}
    Student(const std::string & s, const ArrayDb & a)
        : std::string(s), ArrayDb(a) {}
    Student(const char * str, const double * pd, int n)
        : std::string(str), ArrayDb(pd, n) {}
    ~Student() {}
    
    double Average() const;
    double & operator[](int i);
    double operator[](int i) const;
    const std::string & Name() const;

    // 友元函数
    // 输入
    friend std::istream & operator>>(std::istream & is,
                                   Student & stu);    // 1个单词
    friend std::istream & getline(std::istream & is,
                                Student & stu);    // 1行
    // 输出
    friend std::ostream & operator<<(std::ostream & os,
                                   const Student & stu);
};

#endif
