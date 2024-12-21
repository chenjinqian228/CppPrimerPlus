// error2.cpp -- 返回错误代码
#include <iostream>
#include <cfloat>  // (或 float.h) 用于 DBL_MAX

bool hmean(double a, double b, double * ans);

int main()
{
    double x, y, z;

    std::cout << "请输入两个数字: ";
    while (std::cin >> x >> y)
    {
        if (hmean(x, y, &z))
            std::cout << x << " 和 " << y
                     << " 的调和平均数是 " << z << std::endl;
        else
            std::cout << "其中一个值不应该是另一个值的负数 - "
                     << "请重试。\n";
        std::cout << "请输入下一组数字 <输入q退出>: ";
    }
    std::cout << "再见!\n";
    return 0;
}

bool hmean(double a, double b, double * ans)
{
    if (a == -b)
        return false;
    *ans = 2.0 * a * b / (a + b);
    return true;
}
