//
// sayings1.cpp -- 使用扩展的String类的示例程序
// 
#include <iostream>
#include "12.4_string1.h"
#include "12.5_string1.cpp"
const int ArSize = 10;     // 数组最大容量
const int MaxLen = 81;     // 每条字符串的最大长度

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    String name;

    cout << "您好，请问您的名字是？\n>> ";
    cin >> name;

    cout << name << "，请输入最多 " << ArSize
         << " 条短语（输入空行结束）：\n";
    String sayings[ArSize];     // String对象数组
    char temp[MaxLen];          // 临时字符串存储
    int i;
    for (i = 0; i < ArSize; i++)
    {
        cout << i+1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n')    // 清除多余的输入
            continue;
        if (!cin || temp[0] == '\0')    // 检查是否为空行
            break;              // i不自增
        else
            sayings[i] = temp; // 使用重载的赋值运算符
    }
    int total = i;             // 读取的总行数

    if ( total > 0)
    {
        cout << "以下是您输入的短语：\n";
        for (i = 0; i < total; i++)
            cout << sayings[i][0] << ": " << sayings[i] << endl;

        int shortest = 0;       // 最短短语的索引
        int first = 0;         // 字母顺序第一个的索引
        for (i = 1; i < total; i++)
        {
            // 找出最短的短语
            if (sayings[i].length() < sayings[shortest].length())
                shortest = i;
            // 找出字母顺序第一个
            if (sayings[i] < sayings[first])
                first = i;
        }
        cout << "最短的短语：\n" << sayings[shortest] << endl;
        cout << "按字母顺序排第一的短语：\n" << sayings[first] << endl;
        cout << "本程序使用了 " << String::HowMany() 
             << " 个String对象。再见。\n";
    }
    else
        cout << "没有输入任何内容！再见。\n";
    return 0;
}
