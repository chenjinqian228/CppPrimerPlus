// twoswap.cpp -- 特化版本覆盖模板
#include <iostream>
template <typename T>
void Swap(T &a, T &b);    // 模板原型

struct job
{
    char name[40];    // 姓名
    double salary;    // 薪资
    int floor;        // 楼层
};

template <> void Swap<job>(job &j1, job &j2);   // job类型的显式特化声明



template <typename T>
void Swap(T &a, T &b)    // 通用版本
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

// 只交换job结构中的salary和floor字段
template <> void Swap<job>(job &j1, job &j2)   // 特化版本
{
    double t1;
    int t2;
    t1 = j1.salary;
    j1.salary = j2.salary;
    j2.salary = t1;
    t2 = j1.floor;
    j1.floor = j2.floor;
    j2.floor = t2;
}

int main()
{
    using namespace std;
    cout.precision(2);    // 设置输出精度为2位小数
    cout.setf(ios::fixed, ios::floatfield);
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "使用编译器生成的整数交换函数：\n";
    Swap(i,j);        // 生成 void Swap(int &, int &)
    cout << "交换后 i, j = " << i << ", " << j << ".\n";

    job sue = {"Susan Yaffee", 73000.60, 7};
    job sidney = {"Sidney Taffee", 78060.72, 9};
    cout << "职位交换前：\n";
    cout << "sue = " << sue.name << ": $" << sue.salary
         << " 在第 " << sue.floor << " 层" << endl;
    cout << "sidney = " << sidney.name << ": $" << sidney.salary
         << " 在第 " << sidney.floor << " 层" << endl;
    Swap(sue, sidney);    // 使用 void Swap(job &, job &)
    cout << "职位交换后：\n";
    cout << "sue = " << sue.name << ": $" << sue.salary
         << " 在第 " << sue.floor << " 层" << endl;
    cout << "sidney = " << sidney.name << ": $" << sidney.salary
         << " 在第 " << sidney.floor << " 层" << endl;
    return 0;
}
