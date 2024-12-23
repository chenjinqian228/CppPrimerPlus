// manip.cpp -- 使用格式操纵符
#include <iostream>
int main()
{
    using namespace std;
    cout << "请输入一个整数：";
    int n;
    cin >> n;

    cout << "n    n*n\n";
    cout << n << "    " << n * n << " (十进制)\n";

    // 设置为十六进制模式
    cout << hex;
    cout << n << "    ";
    cout << n * n << " (十六进制)\n";

    // 设置为八进制模式
    cout << oct << n << "    " << n * n << " (八进制)\n";

    // 调用操纵符的另一种方式
    dec(cout);
    cout << n << "    " << n * n << " (十进制)\n";

    return 0;
}
