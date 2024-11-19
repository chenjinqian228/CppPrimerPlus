// use_new.cpp -- 使用 new 运算符的示例
#include <iostream>
int main()
{
    using namespace std;
    int nights = 1001;          // 普通整型变量
    int * pt = new int;         // 为一个整数分配内存空间
    *pt = 1001;                 // 在该内存空间中存储值

    cout << "nights的值 = ";
    cout << nights << "; 地址 = " << &nights << endl;
    cout << "整型指针：";
    cout << "值 = " << *pt << "; 地址 = " << pt << endl;

    double * pd = new double;    // 为一个double类型分配内存空间
    *pd = 1000000.0;            // 在该内存空间中存储double值

    cout << "双精度指针：";
    cout << "值 = " << *pd << "; 地址 = " << pd << endl;
    cout << "指针pd的地址: " << &pd << endl;
    cout << "pt的大小 = " << sizeof(pt);
    cout << "; *pt的大小 = " << sizeof(*pt) << endl;
    cout << "pd的大小 = " << sizeof(pd);
    cout << "; *pd的大小 = " << sizeof(*pd) << endl;

    return 0;
}
