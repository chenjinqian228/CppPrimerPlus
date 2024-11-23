// and.cpp -- 使用逻辑AND运算符
#include <iostream>
const int ArSize = 6;    // 定义数组大小为6
int main()
{
    using namespace std;
    float naaq[ArSize];  // 声明存储NAAQ值的数组
    cout << "请输入邻居们的NAAQ值（新时代意识指数）"
         << "程序将在以下情况终止："
         << "当你输入" << ArSize << "个数值 "
         << "或输入一个负数。\n";

    int i = 0;          // 计数器初始化
    float temp;         // 临时存储输入值
    cout << "请输入第一个值: ";

    cin >> temp;
    while (i < ArSize && temp >= 0)  // 两个退出条件：达到数组大小或输入负数
    {
        naaq[i] = temp;  // 将输入值存入数组
        ++i;
        if (i < ArSize)  // 如果数组还有空间
        {
            cout << "请输入下一个值: ";
            cin >> temp;  // 获取下一个输入值
        }
    }
    if (i == 0)         // 如果没有输入任何有效数据
        cout << "没有数据--再见！\n";
    else
    {
        cout << "请输入你自己的NAAQ值: ";
        float you;       // 存储用户自己的NAAQ值
        cin >> you;
        int count = 0;   // 计数器：记录比用户NAAQ值高的邻居数量
        for (int j = 0; j < i; j++)
            if (naaq[j] > you)
                ++count;
        cout << count;
        cout << " 个邻居的新时代意识指数比你高。\n";
    }
    return 0;
}
