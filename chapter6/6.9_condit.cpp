// condit.cpp -- 使用条件运算符
#include <iostream>
int main()
{
    using namespace std;
    int a, b;                     // 声明两个整数变量
    cout << "请输入两个整数: ";    // 提示用户输入
    cin >> a >> b;                // 读取用户输入的两个数
    cout << "在 " << a << " 和 " << b;
    int c = a > b ? a : b;        // 如果 a > b，则 c = a，否则 c = b
    cout << " 中较大的数是 " << c << endl;
    return 0;
}
