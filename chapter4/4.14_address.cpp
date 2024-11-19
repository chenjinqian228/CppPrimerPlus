// address.cpp -- 使用&运算符查找地址
#include <iostream>
int main()
{
    using namespace std;
    int donuts = 6;        // 声明整型变量甜甜圈并赋值为6
    double cups = 4.5;     // 声明双精度浮点型变量杯子并赋值为4.5

    cout << "甜甜圈的值 = " << donuts;
    cout << " 且甜甜圈的地址 = " << &donuts << endl;
    // 注意：你可能需要使用 unsigned (&donuts)
    // 和 unsigned (&cups)
    cout << "杯子的值 = " << cups;
    cout << " 且杯子的地址 = " << &cups << endl;
    return 0;
}
