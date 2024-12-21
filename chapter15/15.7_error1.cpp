// error1.cpp -- 使用 abort() 函数
#include <iostream>
#include <cstdlib>
double hmean(double a, double b);

int main()
{
    double x, y, z;

    std::cout << "请输入两个数字：";
    while (std::cin >> x >> y)
    {
        z = hmean(x,y);
        std::cout << "数字 " << x << " 和 " << y
            << " 的调和平均数是 " << z << std::endl;
        std::cout << "请输入下一组数字 <输入q退出>：";
    }
    std::cout << "再见！\n";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
    {
        std::cout << "传入 hmean() 的参数不合法\n";
        std::abort();
    }
    return 2.0 * a * b / (a + b);
}
