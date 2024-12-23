// iomanip.cpp -- 使用来自iomanip的操纵符
// 某些系统需要显式链接数学库
#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    using namespace std;
    // 使用新的标准操纵符
    cout << fixed << right;

    // 使用iomanip操纵符
    cout << setw(6) << "N" << setw(14) << "平方根"
         << setw(15) << "四次方根\n";

    double root;
    for (int n = 10; n <= 100; n += 10)
    {
        root = sqrt(double(n));
        cout << setw(6) << setfill('.') << n << setfill(' ')  // 用点填充数字左边的空格
             << setw(12) << setprecision(3) << root           // 设置平方根精度为3位
             << setw(14) << setprecision(4) << sqrt(root)     // 设置四次方根精度为4位
             << endl;
    }

    return 0;
}
