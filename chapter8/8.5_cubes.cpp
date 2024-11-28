// cubes.cpp -- 常规参数和引用参数的示例
#include <iostream>
double cube(double a);           // 常规参数 - 计算立方
double refcube(double &ra);      // 引用参数 - 计算立方
int main()
{
    using namespace std;
    double x = 3.0;             // 测试值为3.0

    cout << cube(x);            // 计算x的立方
    cout << " = " << x << "的立方" << endl;
    cout << refcube(x);         // 使用引用计算x的立方
    cout << " = " << x << "的立方" << endl;
    return 0;
}

double cube(double a)           // 使用常规参数的版本
{
    a *= a * a;                 // 计算立方
    return a;                   // 返回计算结果
}

double refcube(double &ra)      // 使用引用参数的版本
{
    ra *= ra * ra;             // 计算立方
    return ra;                 // 返回计算结果
}
