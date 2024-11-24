// cinfish.cpp -- 非数字输入时终止循环
#include <iostream>
const int Max = 5;    // 定义最大鱼的数量

int main()
{
    using namespace std;
    // 获取数据
    double fish[Max];     // 存储鱼的重量的数组
    cout << "请输入鱼的重量。\n";
    cout << "您最多可以输入 " << Max 
         << " 条鱼（输入q终止）。\n";
    cout << "第1条鱼: ";
    int i = 0;
    while (i < Max && cin >> fish[i]) {    // 当输入有效且未达到最大数量时继续
        if (++i < Max)                      // 如果还可以输入更多
            cout << "第" << i+1 << "条鱼: ";  // 提示输入下一条鱼
    }

    // 计算平均值
    double total = 0.0;           // 初始化总重量
    for (int j = 0; j < i; j++)   // 遍历已输入的鱼的重量
        total += fish[j];         // 累加重量

    // 报告结果
    if (i == 0)                   // 如果没有输入任何数据
        cout << "没有鱼的数据\n";
    else                          // 否则显示平均重量
        cout << total / i << " = " << i << " 条鱼的平均重量\n";
    cout << "程序结束。\n";
    return 0;
}
