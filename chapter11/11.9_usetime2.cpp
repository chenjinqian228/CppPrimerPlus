// usetime2.cpp -- 使用Time类的第三个版本
// 需要将usetime2.cpp和mytime2.cpp一起编译
#include <iostream>
#include "11.7_mytime2.h"
#include "11.8_mytime2.cpp"

int main()
{
    using std::cout;
    using std::endl;
    
    Time weeding(4, 35);        // 创建除草时间对象：4小时35分钟
    Time waxing(2, 47);         // 创建打蜡时间对象：2小时47分钟
    Time total;                 // 用于存储总时间
    Time diff;                  // 用于存储时间差
    Time adjusted;              // 用于存储调整后的时间

    cout << "除草时间 = ";
    weeding.Show();
    cout << endl;

    cout << "打蜡时间 = ";
    waxing.Show();
    cout << endl;

    cout << "总工作时间 = ";
    total = weeding + waxing;    // 使用重载的+运算符
    total.Show();
    cout << endl;

    diff = weeding - waxing;     // 使用重载的-运算符
    cout << "除草时间 - 打蜡时间 = ";
    diff.Show();
    cout << endl;

    adjusted = total * 1.5;      // 使用重载的*运算符
    cout << "调整后的工作时间 = ";
    adjusted.Show();
    cout << endl;
    
    return 0;
}
