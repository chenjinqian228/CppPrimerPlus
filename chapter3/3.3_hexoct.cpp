// hexoct1.cpp -- 展示十六进制和八进制字面量
#include <iostream>
int main()
{
    using namespace std;
    int chest = 42;    // 十进制整数字面量
    int waist = 0x42;  // 十六进制整数字面量
    int inseam = 042;  // 八进制整数字面量

    cout << "先生的身材很出众！\n";
    cout << "胸围 = " << chest << " (十进制的42)\n";
    cout << "腰围 = " << waist << " (十六进制的0x42)\n";
    cout << "内缝 = " << inseam << " (八进制的042)\n";
    return 0;
}
