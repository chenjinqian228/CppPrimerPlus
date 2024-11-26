// fun_ptr.cpp -- 函数指针示例
#include <iostream>

// 函数声明
double betsy(int);
double pam(int);

// 函数声明：第二个参数是指向一个返回double类型且接受int参数的函数的指针
void estimate(int lines, double (*pf)(int));

int main()
{
    using namespace std;
    int code;
    cout << "您需要多少行代码？ ";
    cin >> code;
    cout << "这是Betsy的估算：\n";
    estimate(code, betsy);
    cout << "这是Pam的估算：\n";
    estimate(code, pam);
    return 0;
}

// Betsy的估算函数
double betsy(int lns)
{
    return 0.05 * lns;  // 每行代码需要0.05小时
}

// Pam的估算函数
double pam(int lns)
{
    return 0.03 * lns + 0.0004 * lns * lns;  // 考虑到复杂度增加的估算
}

// estimate函数定义
void estimate(int lines, double (*pf)(int))
{
    using namespace std;
    cout << lines << " 行代码将花费 ";
    cout << (*pf)(lines) << " 小时\n";
}
