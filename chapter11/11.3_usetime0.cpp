// usetime0.cpp -- 使用Time类的第一个版本
// 需要同时编译 usetime0.cpp 和 mytime0.cpp
#include <iostream>
#include "11.1_mytime0.h"
#include "11.2_mytime0.cpp"

int main()
{
    using std::cout;
    using std::endl;
    Time planning;            // 创建一个Time对象，使用默认构造函数
    Time coding(2, 40);       // 创建一个Time对象，初始化为2小时40分钟
    Time fixing(5, 55);       // 创建一个Time对象，初始化为5小时55分钟
    Time total;               // 创建一个Time对象用于存储总时间

    cout << "计划时间 = ";    // 显示计划时间
    planning.Show();
    cout << endl;
 
    cout << "编码时间 = ";    // 显示编码时间
    coding.Show();
    cout << endl;
    
    cout << "修复时间 = ";    // 显示修复时间
    fixing.Show();
    cout << endl;

    total = coding.Sum(fixing);    // 计算编码和修复时间的总和
    cout << "coding.Sum(fixing) = ";    // 显示总时间
    total.Show();
    cout << endl;
    
    return 0;
}
