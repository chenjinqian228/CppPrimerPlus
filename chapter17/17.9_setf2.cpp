// setf2.cpp -- 使用带两个参数的setf()函数来控制格式化输出
#include <iostream>
#include <cmath>

int main()
{
    using namespace std;
    // 使用左对齐，显示正号，显示小数点后的零
    // 设置精度为3位
    cout.setf(ios_base::left, ios_base::adjustfield);
    cout.setf(ios_base::showpos);
    cout.setf(ios_base::showpoint);
    cout.precision(3);
    
    // 使用科学计数法并保存旧的格式设置
    ios_base::fmtflags old = cout.setf(ios_base::scientific,
        ios_base::floatfield);
    cout << "左对齐：\n";
    long n;
    for (n = 1; n <= 41; n+= 10)
    {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double(n)) << "|\n";
    }

    // 改为内部对齐
    cout.setf(ios_base::internal, ios_base::adjustfield);
    // 恢复默认的浮点数显示样式
    cout.setf(old, ios_base::floatfield);

    cout << "内部对齐：\n";
    for (n = 1; n <= 41; n+= 10)
    {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double(n)) << "|\n";
    }

    // 使用右对齐，定点表示法
    cout.setf(ios_base::right, ios_base::adjustfield);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << "右对齐：\n";
    for (n = 1; n <= 41; n+= 10)
    {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double(n)) << "|\n";
    }
    return 0;
}
