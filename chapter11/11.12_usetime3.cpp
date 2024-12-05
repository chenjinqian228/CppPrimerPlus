//usetime3.cpp -- 使用Time类的第四个版本
// 需要将usetime3.cpp和mytime3.cpp一起编译
#include <iostream>
#include "11.10_mytime3.h"
#include "11.11_mytime3.cpp"

int main()
{
    using std::cout;
    using std::endl;
    Time aida(3, 35);      // 创建Time对象aida，设置为3小时35分钟
    Time tosca(2, 48);     // 创建Time对象tosca，设置为2小时48分钟
    Time temp;             // 创建临时Time对象

    cout << "Aida和Tosca的时间：\n";
    cout << aida << " " << tosca << endl;
    temp = aida + tosca;    // 使用重载的加法运算符
    cout << "Aida + Tosca的结果: " << temp << endl;
    temp = aida * 1.17;     // 使用重载的成员乘法运算符
    cout << "Aida * 1.17的结果: " << temp << endl;
    cout << "10.0 * Tosca的结果: " << 10.0 * tosca << endl;

    return 0;
}
