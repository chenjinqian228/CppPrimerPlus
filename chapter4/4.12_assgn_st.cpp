// assgn_st.cpp -- 结构体赋值示例
#include <iostream>
struct inflatable
{
    char name[20];    // 名称
    float volume;     // 体积
    double price;     // 价格
};

int main()
{
    using namespace std;
    inflatable bouquet =
    {
        "向日葵",      // name的值
        0.20,         // volume的值
        12.49        // price的值
    };
    inflatable choice;    // 声明第二个结构体变量，但不初始化
    cout << "花束: " << bouquet.name << " 售价$";
    cout << bouquet.price << endl;
    
    choice = bouquet;     // 将一个结构体赋值给另一个结构体
    cout << "选择: " << choice.name << " 售价$";
    cout << choice.price << endl;
    return 0;
}
