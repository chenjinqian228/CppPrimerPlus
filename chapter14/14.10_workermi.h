// workermi.h -- 使用多重继承的工作类
#ifndef WORKERMI_H_
#define WORKERMI_H_

#include <string>

// Worker是一个抽象基类,定义了工作人员的基本属性和方法
class Worker   // 一个抽象基类
{
private:
    std::string fullname;  // 员工全名
    long id;              // 员工ID
protected:
    virtual void Data() const;  // 显示基本数据
    virtual void Get();         // 获取基本数据
public:
    Worker() : fullname("no one"), id(0L) {}  // 默认构造函数
    Worker(const std::string & s, long n)      // 带参数构造函数
            : fullname(s), id(n) {}
    virtual ~Worker() = 0;                     // 纯虚析构函数,使Worker成为抽象类
    virtual void Set() = 0;                    // 纯虚函数,设置数据
    virtual void Show() const = 0;             // 纯虚函数,显示数据
};

// Waiter类继承自Worker,表示服务员
class Waiter : virtual public Worker
{
private:
    int panache;         // 服务风格评分
protected:
    void Data() const;   // 显示服务员数据
    void Get();          // 获取服务员数据
public:
    Waiter() : Worker(), panache(0) {}
    Waiter(const std::string & s, long n, int p = 0)
            : Worker(s, n), panache(p) {}
    Waiter(const Worker & wk, int p = 0)
            : Worker(wk), panache(p) {}
    void Set();          // 设置服务员数据
    void Show() const;   // 显示服务员信息
};

// Singer类继承自Worker,表示歌手
class Singer : virtual public Worker
{
protected:
    enum {other, alto, contralto, soprano,   // 定义声音类型枚举
          bass, baritone, tenor};
    enum {Vtypes = 7};                       // 声音类型数量
    void Data() const;
    void Get();
private:
    static const char *pv[Vtypes];    // 声音类型的字符串描述
    int voice;                        // 声音类型
public:
    Singer() : Worker(), voice(other) {}
    Singer(const std::string & s, long n, int v = other)
            : Worker(s, n), voice(v) {}
    Singer(const Worker & wk, int v = other)
            : Worker(wk), voice(v) {}
    void Set();
    void Show() const;
};

// SingingWaiter类多重继承自Singer和Waiter,表示会唱歌的服务员
class SingingWaiter : public Singer, public Waiter
{
protected:
    void Data() const;   // 显示会唱歌的服务员数据
    void Get();          // 获取会唱歌的服务员数据
public:
    SingingWaiter() {}   // 默认构造函数
    // 带参数构造函数
    SingingWaiter(const std::string & s, long n, int p = 0,
                  int v = other)
            : Worker(s,n), Waiter(s, n, p), Singer(s, n, v) {}
    // 从Worker对象构造
    SingingWaiter(const Worker & wk, int p = 0, int v = other)
            : Worker(wk), Waiter(wk,p), Singer(wk,v) {}
    // 从Waiter对象构造
    SingingWaiter(const Waiter & wt, int v = other)
            : Worker(wt),Waiter(wt), Singer(wt,v) {}
    // 从Singer对象构造  
    SingingWaiter(const Singer & wt, int p = 0)
            : Worker(wt),Waiter(wt,p), Singer(wt) {}
    void Set();          // 设置数据
    void Show() const;   // 显示信息
};

#endif
