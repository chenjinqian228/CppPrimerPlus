// firstref.cpp -- 定义和使用引用的示例
#include <iostream>
int main()
{
    using namespace std;
    int rats = 101;          // 定义整型变量 rats
    int & rodents = rats;    // rodents 是 rats 的引用
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    rodents++;               // 通过引用增加值
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

// 某些编译器实现可能需要将以下地址
// 转换为 unsigned 类型
    cout << "rats的地址 = " << &rats;
    cout << ", rodents的地址 = " << &rodents << endl;
    return 0;
}
