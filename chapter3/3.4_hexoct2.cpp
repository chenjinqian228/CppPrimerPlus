// hexoct2.cpp -- 以十六进制和八进制显示值
#include <iostream>
using namespace std;
int main()
{
    using namespace std;
    int chest = 42;
    int waist = 42;
    int inseam = 42;

    cout << "先生的身材很出众！" << endl;
    cout << "胸围 = " << chest << " (42的十进制)" << endl;
    cout << hex;       // 操纵符：改变数字进制为十六进制
    cout << "腰围 = " << waist << " (42的十六进制)" << endl;
    cout << oct;       // 操纵符：改变数字进制为八进制
    cout << "内缝 = " << inseam << " (42的八进制)" << endl;
    return 0;
}
