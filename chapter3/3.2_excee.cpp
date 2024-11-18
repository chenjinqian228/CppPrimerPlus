// exceed.cpp -- 超出一些整数类型的限制值演示
#include <iostream>
#define ZERO 0         // 定义符号 ZERO 表示数值 0
#include <climits>     // 定义 INT_MAX 作为最大整数值
int main()
{
    using namespace std;
    short sam = SHRT_MAX;      // 将变量初始化为 short 类型的最大值
    unsigned short sue = sam;   // 将 sam 的值赋给 sue（sam 变量已定义，所以没问题）

    cout << "Sam 有 " << sam << " 美元，Sue 有 " << sue;
    cout << " 美元存款。" << endl;
    cout << "给每个账户加 $1。" << endl << "现在 ";
    
    sam = sam + 1;
    sue = sue + 1;
    cout << "Sam 有 " << sam << " 美元，Sue 有 " << sue;
    cout << " 美元存款。\n可怜的 Sam！" << endl;

    sam = ZERO;
    sue = ZERO;
    cout << "Sam 有 " << sam << " 美元，Sue 有 " << sue;
    cout << " 美元存款。" << endl;
    cout << "从每个账户取出 $1。" << endl << "现在 ";
    
    sam = sam - 1;
    sue = sue - 1;
    cout << "Sam 有 " << sam << " 美元，Sue 有 " << sue;
    cout << " 美元存款。" << endl << "幸运的 Sue！" << endl;
    return 0;
}
