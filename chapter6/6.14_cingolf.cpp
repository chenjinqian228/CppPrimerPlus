// cingolf.cpp -- 跳过非数字输入
#include <iostream>
const int Max = 5;    // 定义最大轮数

int main()
{
    using namespace std;
    // 获取数据
    int golf[Max];    // 存储高尔夫得分的数组
    cout << "请输入您的高尔夫得分。\n";
    cout << "您必须输入 " << Max << " 轮。\n";
    int i;
    for (i = 0; i < Max; i++)
    {
        cout << "第" << i+1 << "轮: ";
        while (!(cin >> golf[i])) {    // 当输入无效时
            cin.clear();                // 重置输入流
            while (cin.get() != '\n')   // 读取并丢弃错误输入
                continue;               // 直到行尾
            cout << "请输入一个数字: ";  // 提示重新输入
        }
    }

    // 计算平均值
    double total = 0.0;            // 初始化总分
    for (i = 0; i < Max; i++)      // 遍历所有得分
        total += golf[i];          // 累加得分

    // 报告结果
    cout << total / Max << " = " << Max << " 轮的平均得分\n";
    return 0;
}
