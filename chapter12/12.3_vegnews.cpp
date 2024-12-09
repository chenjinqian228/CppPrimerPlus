// vegnew.cpp -- 在类中使用new和delete
#include <iostream>
using std::cout;
#include "12.1_stringBad.h"
#include "12.2_stringBad.cpp"

void callme1(StringBad &);  // 按引用传递
void callme2(StringBad);    // 按值传递

int main()
{
    using std::endl;
    {
        cout << "开始一个内部块。\n";
        StringBad headline1("Celery Stalks at Midnight");    // 第一个标题
        StringBad headline2("Lettuce Prey");                 // 第二个标题
        StringBad sports("Spinach Leaves Bowl for Dollars"); // 体育新闻
        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;
        callme1(headline1);                                  // 引用传递
        cout << "headline1: " << headline1 << endl;
        callme2(headline2);                                  // 值传递
        cout << "headline2: " << headline2 << endl;
        cout << "用一个对象初始化另一个对象：\n";
        StringBad sailor = sports;                           // 使用复制构造函数
        cout << "sailor: " << sailor << endl;
        cout << "将一个对象赋值给另一个对象：\n";
        StringBad knot;                                      // 默认构造函数
        knot = headline1;                                    // 使用赋值运算符
        cout << "knot: " << knot << endl;
        cout << "退出代码块。\n";
    }
    cout << "main()函数结束\n";
    return 0;
}

void callme1(StringBad & rsb)
{
    cout << "通过引用传递的字符串：\n";
    cout << "    \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
    cout << "通过值传递的字符串：\n";
    cout << "    \"" << sb << "\"\n";
}
