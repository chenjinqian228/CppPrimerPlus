// stone.cpp -- 用户自定义转换
// 需要与stonewt.cpp一起编译
#include <iostream>
using std::cout;
#include "11.16_stonewt.h"
#include "11.17_stonewt.cpp"

void display(const Stonewt & st, int n);

int main()
{
    Stonewt incognito = 275;    // 使用构造函数进行初始化
    Stonewt wolfe(285.7);       // 等同于 Stonewt wolfe = 285.7;
    Stonewt taft(21, 8);

    cout << "这位名人的体重是 ";
    incognito.show_stn();
    cout << "这位侦探的体重是 ";
    wolfe.show_stn();
    cout << "这位总统的体重是 ";
    taft.show_lbs();
    incognito = 276.8;          // 使用构造函数进行转换
    taft = 325;                 // 等同于 taft = Stonewt(325);
    cout << "晚餐后，这位名人的体重是 ";
    incognito.show_stn();
    cout << "晚餐后，这位总统的体重是 ";
    taft.show_lbs();
    display(taft, 2);
    cout << "这位摔跤手的体重更重。\n";
    display(422, 2);
    cout << "没有一块石头未被翻转\n";
    return 0;
}

void display(const Stonewt & st, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "哇！ ";
        st.show_stn();
    }
}
