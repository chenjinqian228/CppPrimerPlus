// error5.cpp -- 展开堆栈
#include <iostream>
#include <cmath> // 或 math.h，unix用户可能需要-lm标志
#include <string>
#include "15.10_exc_mean.h"

// demo类用于演示对象的创建和销毁顺序
class demo
{
private:
    std::string word;  // 存储对象的名称
public:
    // 构造函数,创建对象时打印消息
    demo (const std::string & str)
    {
        word = str;
        std::cout << "demo " << word << " 已创建\n";
    }
    // 析构函数,销毁对象时打印消息
    ~demo()
    {
        std::cout << "demo " << word << " 已销毁\n"; 
    }
    // 显示对象存在的消息
    void show() const
    {
        std::cout << "demo " << word << " 存在!\n";
    }
};

// 函数原型
double hmean(double a, double b);  // 计算调和平均数
double gmean(double a, double b);  // 计算几何平均数
double means(double a, double b);  // 计算三种平均数的平均值

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    
    double x, y, z;
    {
        demo d1("在main()代码块中找到");  // 创建一个demo对象
        cout << "请输入两个数字: ";
        while (cin >> x >> y)
        {
            try {                  // 尝试计算平均值
                z = means(x,y);
                cout << x << " 和 " << y
                    << " 的平均值是 " << z << endl;
                cout << "请输入下一对数字: ";
            }                     
            catch (bad_hmean & bg)    // 捕获调和平均数异常
            {
                bg.mesg();
                cout << "请重试.\n";
                continue;
            }
            catch (bad_gmean & hg)    // 捕获几何平均数异常
            {
                cout << hg.mesg();
                cout << "使用的值: " << hg.v1 << ", " 
                     << hg.v2 << endl;
                cout << "抱歉,你不能继续玩了.\n";
                break;
        }
    }
        d1.show();
}
    cout << "再见!\n";
    return 0;
}

// 计算三种平均数的平均值
double means(double a, double b)
{
    demo d2("在means()中找到");  // 创建第一个demo对象
    double am, hm, gm;
    demo d3("在means()中找到");  // 创建第二个demo对象
    am = (a + b) / 2.0;    // 计算算术平均值
    try
    {
        hm = hmean(a,b);   // 计算调和平均值
        gm = gmean(a,b);   // 计算几何平均值
    }
    catch (bad_hmean & bg) // 捕获并重新抛出调和平均数异常
    {
        bg.mesg();
        std::cout << "在means()中捕获\n";
        throw;             // 重新抛出异常
    }
    d3.show();
    return (am + hm + gm) / 3.0;  // 返回三种平均值的平均数
}

// 计算调和平均数
double hmean(double a, double b)
{
    if (a == -b)    // 如果分母为0则抛出异常
        throw bad_hmean(a,b);
    return 2.0 * a * b / (a + b);
}

// 计算几何平均数
double gmean(double a, double b)
{
    if (a < 0 || b < 0)    // 如果有负数则抛出异常
        throw bad_gmean(a,b);
    return std::sqrt(a * b); 
}
