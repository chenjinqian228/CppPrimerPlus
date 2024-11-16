// hexoct2.cpp -- 以十六进制和八进制显示值
#include <iostream>
using namespace std;
int main()
{
    using namespace std;
    int chest = 42;
    int waist = 42;
    int inseam = 42;

    cout << "Monsieur cuts a striking figure!" << endl;
    cout << "chest = " << chest << " (decimal for 42)" << endl;
    cout << hex;       // 操纵符：改变数字进制为十六进制
    cout << "waist = " << waist << " (hexadecimal for 42)" << endl;
    cout << oct;       // 操纵符：改变数字进制为八进制
    cout << "inseam = " << inseam << " (octal for 42)" << endl;
    return 0;
}
