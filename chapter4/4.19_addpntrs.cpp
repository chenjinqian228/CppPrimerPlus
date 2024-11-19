// addpntrs.cpp -- 指针加法演示
#include <iostream>
int main()
{
    using namespace std;
    // 定义一个存储工资的双精度数组
    double wages[3] = {10000.0, 20000.0, 30000.0};
    // 定义一个存储短整型数据的数组
    short stacks[3] = {3, 2, 1};

    // 获取数组地址的两种方式
    double * pw = wages;      // 方式1：数组名就是数组地址
    short * ps = &stacks[0];  // 方式2：使用地址运算符获取数组第一个元素的地址
    
    // 输出指针的值和指针指向的值
    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    // 指针加1（向后移动一个double类型的长度）
    pw = pw + 1;
    cout << "将pw指针加1后:\n";
    cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";
    
    // 输出短整型指针的值和指向的值
    cout << "ps = " << ps << ", *ps = " << *ps << endl;
    // 指针加1（向后移动一个short类型的长度）
    ps = ps + 1;
    cout << "将ps指针加1后:\n";
    cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";

    // 使用数组符号访问元素
    cout << "使用数组符号访问两个元素\n";
    cout << "stacks[0] = " << stacks[0]
         << ", stacks[1] = " << stacks[1] << endl;
    
    // 使用指针符号访问元素
    cout << "使用指针符号访问两个元素\n";
    cout << "*stacks = " << *stacks
         << ", *(stacks + 1) = " << *(stacks + 1) << endl;

    // 输出数组和指针的大小
    cout << sizeof(wages) << " = wages数组的大小（字节）\n";
    cout << sizeof(pw) << " = pw指针的大小（字节）\n";
    return 0;
}
