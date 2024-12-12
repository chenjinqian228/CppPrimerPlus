// workmi.cpp -- 多重继承
// 与 workermi.cpp 一起编译
#include <iostream>
#include <cstring>
#include "14.10_workermi.h"
#include "14.11_workermi.cpp"

const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    // 创建一个Worker指针数组,用于存储不同类型的员工对象
    Worker * lolas[SIZE];

    int ct; // 记录实际创建的员工数量
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        // 显示员工类型选择菜单
        cout << "请输入员工类别:\n"
            << "w: 服务员  s: 歌手  "
            << "t: 歌唱服务员  q: 退出\n";
        cin >> choice;
        // 验证输入的选择是否有效
        while (strchr("wstq", choice) == NULL)
        {
            cout << "请输入 w、s、t 或 q: ";
            cin >> choice;
        }
        // 如果选择退出则跳出循环
        if (choice == 'q')
            break;
        // 根据选择创建相应类型的员工对象
        switch(choice)
        {
            case 'w':   lolas[ct] = new Waiter; // 创建服务员对象
                        break;
            case 's':   lolas[ct] = new Singer; // 创建歌手对象
                        break;
            case 't':   lolas[ct] = new SingingWaiter; // 创建歌唱服务员对象
                        break;
        }
        cin.get(); // 清除输入缓冲区
        lolas[ct]->Set(); // 设置员工信息
    }

    // 显示所有员工信息
    cout << "\n以下是您的员工:\n";
    int i;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        lolas[i]->Show();
    }
    // 释放动态分配的内存
    for (i = 0; i < ct; i++)
        delete lolas[i];
    cout << "再见。\n";
    return 0; 
}
