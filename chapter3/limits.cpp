// limits.cpp -- 一些整数类型的限制演示
#include <iostream>
#include <climits>      // 在旧系统中使用 limits.h
int main()
{
    using namespace std;
    int n_int = INT_MAX;        // 将 n_int 初始化为 int 类型的最大值
    short n_short = SHRT_MAX;   // 这些符号都定义在 climits 文件中
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    // sizeof 运算符用于获取类型或变量的字节大小
    cout << "int is " << sizeof(int) << " bytes." << endl;
    cout << "short is " << sizeof n_short << " bytes." << endl;
    cout << "long is " << sizeof n_long << " bytes." << endl;
    cout << "long long is " << sizeof n_llong << " bytes." << endl;
    cout << endl;

    cout << "Maximum values:" << endl;
    cout << "int: " << n_int << endl;
    cout << "short: " << n_short << endl;
    cout << "long: " << n_long << endl;
    cout << "long long: " << n_llong << endl << endl;

    cout << "Minimum int value = " << INT_MIN << endl;
    cout << "Bits per byte = " << CHAR_BIT << endl;
    return 0;
}
