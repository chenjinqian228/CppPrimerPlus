// ourfunc.cpp -- 定义自己的函数
#include <iostream>

void simon(int);    // simon()函数的原型声明

int main()
{
    using namespace std;
    simon(3);       // 调用simon()函数
    cout << "请输入一个整数：";
    int count;
    cin >> count;
    simon(count);   // 再次调用函数
    cout << "完成！" << endl;
    return 0;
}

void simon(int n)   // 定义simon()函数
{
    using namespace std;
    cout << "西蒙说请弯腰触摸脚尖 " << n << " 次。" << endl;
}   // void函数不需要返回语句
