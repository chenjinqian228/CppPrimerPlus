// protos.cpp -- 使用函数原型和函数调用示例
#include <iostream>

void cheers(int);      // 原型：无返回值
double cube(double x); // 原型：返回double类型值

int main()
{
    using namespace std;
    cheers(5);         // 函数调用
    cout << "请输入一个数字：";
    double side;
    cin >> side;
    double volume = cube(side);    // 函数调用
    cout << "一个边长为" << side << "英尺的立方体体积为";
    cout << volume << "立方英尺。\n";
    cheers(cube(2));   // 展示函数原型保护的作用
    return 0;
}

void cheers(int n)
{
    using namespace std;
    for (int i = 0; i < n; i++)
        cout << "干杯！";
    cout << endl;
}

double cube(double x)
{
    return x * x * x;
}
