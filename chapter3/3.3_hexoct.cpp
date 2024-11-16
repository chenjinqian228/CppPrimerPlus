// hexoct1.cpp -- 展示十六进制和八进制字面量
#include <iostream>
int main()
{
    using namespace std;
    int chest = 42;    // 十进制整数字面量
    int waist = 0x42;  // 十六进制整数字面量
    int inseam = 042;  // 八进制整数字面量

    cout << "Monsieur cuts a striking figure!\n";
    cout << "chest = " << chest << " (42 in decimal)\n";
    cout << "waist = " << waist << " (0x42 in hex)\n";
    cout << "inseam = " << inseam << " (042 in octal)\n";
    return 0;
}
