// temptempover.cpp -- 模板重载示例
#include <iostream>

template <typename T>            // 模板 A
void ShowArray(T arr[], int n);

// template <typename T>            // 模板 B
// void ShowArray(T * arr[], int n);

// 定义债务结构体
struct debts
{
    char name[50];    // 姓名
    double amount;    // 金额
};

int main()
{
    using namespace std;
    // 创建一个整数数组
    int things[6] = {13, 31, 103, 301, 310, 130};
    
    // 创建债务人数组
    struct debts mr_E[3] =
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
    
    // 创建指向 double 的指针数组
    double * pd[3]; 

    // 将指针设置为指向 mr_E 结构体数组中的 amount 成员
    for (int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;
    
    cout << "列出 Mr. E 的物品清单：\n";
    // things 是一个整数数组
    ShowArray(things, 6);  // 使用模板 A
    
    cout << "列出 Mr. E 的债务：\n";
    // pd 是一个指向 double 的指针数组
    ShowArray(pd, 3);      // 使用模板 B
    return 0;
}

// 模板 A 的定义：用于显示普通数组
template <typename T>
void ShowArray(T arr[], int n)
{
    using namespace std;
    cout << "模板 A\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

// 模板 B 的定义：用于显示指针数组
// template <typename T>
// void ShowArray(T * arr[], int n)
// {
//     using namespace std;
//     cout << "模板 B\n";
//     for (int i = 0; i < n; i++)
//         cout << *arr[i] << ' ';  // 解引用指针来显示值
//     cout << endl;
// }
