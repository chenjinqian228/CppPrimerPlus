// usestok1.cpp -- 使用 Stock 类
// 需要与 stock10.cpp 一起编译
#include <iostream>
#include "10.4_stock10.h"
#include "10.5_stock10.cpp"

int main()
{
    {
        using std::cout;
        cout << "使用构造函数创建新对象\n";
        Stock stock1("NanoSmart", 12, 20.0);          // 语法方式1
        stock1.show();
        Stock stock2 = Stock("Boffo Objects", 2, 2.0); // 语法方式2
        stock2.show();

        cout << "将 stock1 赋值给 stock2:\n";
        stock2 = stock1;
        cout << "列出 stock1 和 stock2 的信息:\n";
        stock1.show();
        stock2.show();

        cout << "使用构造函数重置一个对象\n";
        stock1 = Stock("Nifty Foods", 10, 50.0);      // 临时对象
        cout << "更新后的 stock1:\n";
        stock1.show();
        cout << "程序结束\n";
    }
    return 0;
}
