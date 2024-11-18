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
    cout << "int 占用 " << sizeof(int) << " 字节。" << endl;
    cout << "short 占用 " << sizeof n_short << " 字节。" << endl;
    cout << "long 占用 " << sizeof n_long << " 字节。" << endl;
    cout << "long long 占用 " << sizeof n_llong << " 字节。" << endl;
    cout << endl;

    cout << "最大值：" << endl;
    cout << "int：" << n_int << endl;
    cout << "short：" << n_short << endl;
    cout << "long：" << n_long << endl;
    cout << "long long：" << n_llong << endl << endl;

    cout << "int 的最小值 = " << INT_MIN << endl;
    cout << "每字节的位数 = " << CHAR_BIT << endl;
    return 0;
}
