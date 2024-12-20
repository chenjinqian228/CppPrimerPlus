//str1.cpp -- 介绍string类
#include <iostream>
#include <string>
//使用string构造函数
int main()
{
    using namespace std;
    string one("Lottery Winner!"); // 构造函数 #1
    cout << one << endl;           // 重载的 << 运算符
    string two(20, '$');           // 构造函数 #2
    cout << two << endl;
    string three(one);             // 构造函数 #3
    cout << three << endl;
    one += " Oops!";               // 重载的 += 运算符
    cout << one << endl;
    two = "Sorry! That was ";
    three[0] = 'P';               // 将three的第一个字符改为'P'
    string four;                   // 构造函数 #4
    four = two + three;            // 重载的 + 运算符
    cout << four << endl;
    char alls[] = "All's well that ends well";
    string five(alls, 20);         // 构造函数 #5
    cout << five << "!\n";
    string six(alls + 6, alls + 10); // 构造函数 #6
    cout << six << ", ";
    string seven(&alls[6], &alls[10]); // 再次使用构造函数 #6
    cout << seven << "...\n";
    string eight(four, 7, 16);     // 构造函数 #7
    cout << eight << " in motion!" << endl;
    return 0;
}