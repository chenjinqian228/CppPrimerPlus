// worktest.cpp -- 测试工人类继承体系
// 该程序演示了Worker类继承体系中的继承和多态
#include <iostream>
#include "14.7_worker0.h"
#include "14.8_worker0.cpp"

const int LIM = 4; // 工人数组的大小限制
int main()
{
    // 创建Waiter和Singer对象并设置初始值
    Waiter bob("Bob Apple", 314L, 5);  // 姓名, ID, 潇洒度
    Singer bev("Bev Holle", 522L, 3);  // 姓名, ID, 声部
    
    // 创建默认的Waiter和Singer对象
    Waiter w_temp;  // 使用默认构造函数
    Singer s_temp;  // 使用默认构造函数

    // 创建Worker指针数组并用对象初始化
    Worker *pw[LIM] = {&bob, &bev, &w_temp, &s_temp};

    int i;
    // 为未初始化的工人设置值(索引2-3)
    for (i = 2; i < LIM; i++)
        pw[i]->Set();
    
    // 显示所有工人的信息
    for (i = 0; i < LIM; i++)
    {
        pw[i]->Show();  // 通过虚函数调用适当的Show()
        std::cout << std::endl;
    }
    return 0;
}
