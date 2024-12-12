// worker0.h -- 工作类
#ifndef WORKER0_H_
#define WORKER0_H_

#include <string>

class Worker   // 抽象基类
{
private:
    std::string fullname;  // 员工全名
    long id;              // 员工ID
public:
    Worker() : fullname("no one"), id(0L) {}  // 默认构造函数
    Worker(const std::string & s, long n)      // 带参数的构造函数
            : fullname(s), id(n) {}
    virtual ~Worker() = 0;  // 纯虚析构函数,使Worker成为抽象类
    virtual void Set();     // 设置员工信息的虚函数
    virtual void Show() const;  // 显示员工信息的虚函数
};

class Waiter : public Worker  // 服务员类,继承自Worker
{
private:
    int panache;  // 服务员的风度等级
public:
    Waiter() : Worker(), panache(0) {}  // 默认构造函数
    Waiter(const std::string & s, long n, int p = 0)  // 带参数的构造函数
            : Worker(s, n), panache(p) {}
    Waiter(const Worker & wk, int p = 0)  // 复制构造函数
            : Worker(wk), panache(p) {}
    void Set();    // 重写基类的Set函数
    void Show() const;  // 重写基类的Show函数
};

class Singer : public Worker  // 歌手类,继承自Worker 
{
protected:
    enum {other, alto, contralto, soprano,  // 声音类型枚举
          bass, baritone, tenor};
    enum {Vtypes = 7};  // 声音类型总数
private:
    static const char *pv[Vtypes];    // 声音类型的字符串描述数组
    int voice;  // 歌手的声音类型
public:
    Singer() : Worker(), voice(other) {}  // 默认构造函数
    Singer(const std::string & s, long n, int v = other)  // 带参数的构造函数
            : Worker(s, n), voice(v) {}
    Singer(const Worker & wk, int v = other)  // 复制构造函数
            : Worker(wk), voice(v) {}
    void Set();    // 重写基类的Set函数
    void Show() const;  // 重写基类的Show函数
};

#endif
