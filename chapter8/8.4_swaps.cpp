// swaps.cpp -- 交换变量的示例
#include <iostream>
void swapv(int a, int b);                    // a, b 是新变量（值传递）
void swapp(int* p, int* q);                  // p, q 是整数的地址（指针传递）
void swapr(int& a, int& b);                  // a, b 是别名（引用传递）
int main()
{
    using namespace std;
    int wallet1 = 300;    // 钱包1，300元
    int wallet2 = 350;    // 钱包2，350元

    cout << "钱包1 = $" << wallet1;
    cout << " 钱包2 = $" << wallet2 << endl;

    cout << "使用指针交换内容：\n";
    swapp(&wallet1, &wallet2);   // 传递地址
    cout << "钱包1 = $" << wallet1;
    cout << " 钱包2 = $" << wallet2 << endl;

    cout << "使用引用交换内容：\n";
    swapr(wallet1, wallet2);     // 传递变量
    cout << "钱包1 = $" << wallet1;
    cout << " 钱包2 = $" << wallet2 << endl;

    cout << "尝试使用值传递：\n";
    swapv(wallet1, wallet2);     // 传递值
    cout << "钱包1 = $" << wallet1;
    cout << " 钱包2 = $" << wallet2 << endl;

    return 0;
}

void swapv(int a, int b)     // 尝试使用值传递
{
    int temp;

    temp = a;        // 使用临时变量
    a = b;
    b = temp;
}   // 函数结束时，局部变量 a、b 被销毁

void swapp(int* p, int* q)   // 使用指针
{
    int temp;

    temp = *p;       // 使用临时变量
    *p = *q;
    *q = temp;
}

void swapr(int& a, int& b)   // 使用引用
{
    int temp;

    temp = a;        // 使用临时变量
    a = b;
    b = temp;
}
