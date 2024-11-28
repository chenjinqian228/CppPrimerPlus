// secref.cpp -- 定义和使用引用的示例
#include <iostream>
int main()
{
    using namespace std;
    int rats = 101;          // 定义整型变量 rats
    int & rodents = rats;    // rodents 是 rats 的引用

    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "rats的地址 = " << &rats;
    cout << ", rodents的地址 = " << &rodents << endl;

    int bunnies = 50;        // 定义新变量 bunnies
    rodents = bunnies;       // 我们能改变引用吗？
    cout << "bunnies = " << bunnies;
    cout << ", rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "bunnies的地址 = " << &bunnies;
    cout << ", rodents的地址 = " << &rodents << endl;
    return 0;
}
