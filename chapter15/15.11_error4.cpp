// error4.cpp -- 使用异常类
#include <iostream>
#include <cmath>
#include "15.10_exc_mean.h"

// 函数原型
double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    
    double x, y, z;
    
    cout << "请输入两个数字: ";
    while (cin >> x >> y)
    {
        try {                   // try块开始
            z = hmean(x,y);
            cout << x << " 和 " << y << " 的调和平均数是 "
                 << z << endl;
            cout << x << " 和 " << y << " 的几何平均数是 "
                 << gmean(x,y) << endl;
            cout << "请输入下一组数字 <输入q退出>: ";
        }                       // try块结束
        catch (bad_hmean & bg)    // catch块开始
        {
            bg.mesg();
            cout << "请重试。\n";
            continue;
        }
        catch (bad_gmean & hg) 
        {
            cout << hg.mesg();
            cout << "使用的值: " << hg.v1 << ", " 
                 << hg.v2 << endl;
            cout << "抱歉,您不能继续玩了。\n";
            break;
        }                       // catch块结束
    }
    cout << "再见!\n";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean(a,b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a,b);
    return std::sqrt(a * b); 
}
