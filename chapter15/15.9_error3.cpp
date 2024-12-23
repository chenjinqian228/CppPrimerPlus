// error3.cpp -- 使用异常处理
#include <iostream>
#include <string>
double hmean(double a, double b);

int main()
{
    double x, y, z;

    std::cout << "请输入两个数字: ";
    while (std::cin >> x >> y)
    {
        try {                   // try块开始
            z = hmean(x,y);
        }                       // try块结束
        catch (const char * s)  // 异常处理程序开始
        {
            std::cout << s << std::endl;
            std::cout << "请输入一对新的数字: ";
            continue;
        }                      // 处理程序结束
        std::cout << x << " 和 " << y << " 的调和平均数是 "
                << z << std::endl;
        std::cout << "请输入下一组数字 <输入q退出>: ";
    }
    std::cout << "再见!\n";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw "hmean()参数错误: 不允许 a = -b";
    return 2.0 * a * b / (a + b);
}
