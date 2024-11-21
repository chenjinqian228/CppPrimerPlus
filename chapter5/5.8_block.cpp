// block.cpp -- 使用代码块语句演示
#include <iostream>
int main()
{
    using namespace std;
    cout << "神奇的计算精灵将为您求和和平均值 ";
    cout << "请输入五个数字。\n";
    cout << "请输入五个值：\n";
    double number;    // 用于存储输入的数字
    double sum = 0.0; // 用于存储总和
    for (int i = 1; i <= 5; i++)
    {                               // 代码块开始
        cout << "第" << i << "个值: ";
        cin >> number;
        sum += number;             // 累加输入的数字
    }                              // 代码块结束
    cout << "五个绝妙的选择！ ";
    cout << "它们的总和是 " << sum << endl;
    cout << "平均值是 " << sum / 5 << "。\n";
    cout << "神奇的计算精灵向您告别！\n";
    return 0;
}
