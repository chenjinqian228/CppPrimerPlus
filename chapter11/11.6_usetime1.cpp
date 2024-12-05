// usetime1.cpp -- 使用Time类的第二个版本
#include <iostream>
#include "11.4_mytime1.h"
#include "11.5_mytime1.cpp"

int main()
{
    using std::cout;
    using std::endl;
    Time planning;                  // 创建planning对象（使用默认构造函数）
    Time coding(2, 40);            // 创建coding对象，设置为2小时40分钟
    Time fixing(5, 55);            // 创建fixing对象，设置为5小时55分钟
    Time total;                    // 创建total对象（使用默认构造函数）

    cout << "计划时间 = ";
    planning.Show();
    cout << endl;
 
    cout << "编码时间 = ";
    coding.Show();
    cout << endl;
    
    cout << "修复时间 = ";
    fixing.Show();
    cout << endl;

    total = coding + fixing;       // 使用重载的+运算符
    cout << "编码 + 修复 = ";
    total.Show();
    cout << endl;

    Time morefixing(3, 28);       // 创建morefixing对象，设置为3小时28分钟
    cout << "更多修复时间 = ";
    morefixing.Show();
    cout << endl;
    total = morefixing.operator+(total);    // 显式调用重载的+运算符
    cout << "morefixing.operator+(total) = ";
    total.Show();
    cout << endl;
    // std::cin.get();            // 等待用户输入（已注释）
    return 0;
}
