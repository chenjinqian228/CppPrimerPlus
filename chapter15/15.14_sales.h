// sales.h -- 异常和继承
#ifndef SALES_H_
#define SALES_H_

#include <stdexcept>
#include <string>

// 销售基类
class Sales {
public:
    enum {MONTHS = 12};   // 定义常量表示12个月
    
    // 定义一个异常类,用于处理索引错误
    class bad_index : public std::logic_error {
    private:
        int bi;  // 错误的索引值
    public:
        explicit bad_index(int ix, const std::string & s = "Sales对象中的索引错误\n");
        int bi_val() const { return bi; }  // 获取错误索引值
        virtual ~bad_index() throw() {}     // 虚析构函数
    };
    explicit Sales(int yy = 0);  // 构造函数,设置年份
    Sales(int yy, const double * gr, int n);  // 构造函数,设置年份和销售数据
    virtual ~Sales() {}  // 虚析构函数
    int Year() const { return year; }  // 获取年份
    virtual double operator[](int i) const;  // 重载[]运算符,返回const引用
    virtual double & operator[](int i);      // 重载[]运算符,返回非const引用

private:
    double gross[MONTHS];  // 存储12个月的销售数据
    int year;             // 年份
};

// 带标签的销售类,继承自Sales
class LabeledSales : public Sales {
public:
    // 定义一个异常类,继承自Sales::bad_index
    class nbad_index : public Sales::bad_index {
    private:
        std::string lbl;  // 标签
    public:
        nbad_index(const std::string & lb, int ix, 
                  const std::string & s = "LabeledSales对象中的索引错误\n");
        const std::string & label_val() const { return lbl; }  // 获取标签值
        virtual ~nbad_index() throw() {}  // 虚析构函数
    };
    explicit LabeledSales(const std::string & lb = "none", int yy = 0);  // 构造函数
    LabeledSales(const std::string & lb, int yy, const double * gr, int n);  // 构造函数
    virtual ~LabeledSales() {}  // 虚析构函数
    const std::string & Label() const { return label; }  // 获取标签
    virtual double operator[](int i) const;  // 重载[]运算符,返回const引用
    virtual double & operator[](int i);      // 重载[]运算符,返回非const引用

private:
    std::string label;  // 标签
};

#endif
