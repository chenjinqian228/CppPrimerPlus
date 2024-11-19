// strtype2.cpp -- 演示字符串的赋值、相加和追加操作
#include <iostream>
#include <string>      // 引入string类
int main()
{
    using namespace std;
    string s1 = "penguin";    // 创建并初始化一个string对象
    string s2, s3;            // 创建两个空的string对象

    cout << "你可以将一个字符串对象赋值给另一个: s2 = s1\n";
    s2 = s1;                  // string对象之间的赋值
    cout << "s1: " << s1 << ", s2: " << s2 << endl;

    cout << "你可以将C风格字符串赋值给string对象。\n";
    cout << "s2 = \"buzzard\"\n";
    s2 = "buzzard";           // 将C风格字符串赋值给string对象
    cout << "s2: " << s2 << endl;

    cout << "你可以连接字符串: s3 = s1 + s2\n";
    s3 = s1 + s2;            // 字符串连接，结果存储在s3中
    cout << "s3: " << s3 << endl;

    cout << "你可以追加字符串。\n";
    s1 += s2;                // 使用+=运算符追加字符串
    cout << "s1 += s2 得到 s1 = " << s1 << endl;
    s2 += " for a day";      // 追加C风格字符串
    cout << "s2 += \" for a day\" 得到 s2 = " << s2 << endl;

    return 0;
}
