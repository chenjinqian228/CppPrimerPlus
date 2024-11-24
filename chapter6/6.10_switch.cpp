// switch.cpp -- 使用switch语句
#include <iostream>
using namespace std;

void showmenu();    // 函数原型声明
void report();
void comfort();

int main()
{
    showmenu();
    int choice;
    cin >> choice;
    while (choice != 5)    // 当选择不是5时继续循环
    {
        switch(choice)
        {
            case 1:     cout << "\a\n";         // 发出警报声
                       break;
            case 2:     report();               // 显示报告
                       break;
            case 3:     cout << "老板今天一整天都在。\n";
                       break;
            case 4:     comfort();              // 显示安慰信息
                       break;
            default:    cout << "这不是一个有效的选项。\n";
        }
        showmenu();
        cin >> choice;
    }
    cout << "再见。\n";
    return 0;
}

void showmenu()
{
    cout << "请输入1、2、3、4或5：\n"
         << "1) 警报           2) 报告\n"
         << "3) 借口           4) 安慰\n"
         << "5) 退出\n";
}

void report()
{
    cout << "本周业务情况非常出色。\n"
         << "销售额上升120%。支出下降35%。\n";
}

void comfort()
{
    cout << "您的员工认为您是最优秀的首席财务官\n"
         << "在这个行业中。董事会认为\n"
         << "您是这个行业最优秀的首席执行官。\n";
}
