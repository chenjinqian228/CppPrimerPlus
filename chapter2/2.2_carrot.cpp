// carrots.cpp -- 食品处理程序
// 使用并显示一个变量

#include <iostream>

int main()
{
    using namespace std;

    int carrots;        // 声明一个整型变量

    carrots = 25;       // 给变量赋值
    cout << "I have ";
    cout << carrots;    // 显示变量的值
    cout << " carrots.";
    cout << endl;
    carrots = carrots - 1;  // 修改变量
    cout << "Crunch, crunch. Now I have " << carrots << " carrots." << endl;
    return 0;
}
