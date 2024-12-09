// sayings2.cpp -- 使用指向对象的指针
#include <iostream>
#include <cstdlib>      // 用于 rand()、srand() 函数
#include <ctime>        // 用于 time() 函数
#include "12.4_string1.h"
#include "12.5_string1.cpp"
const int ArSize = 10;  // 数组大小
const int MaxLen = 81;  // 最大字符串长度

int main()
{
    using namespace std;
    String name;
    cout << "你好，你叫什么名字？\n>> ";
    cin >> name;

    cout << name << "，请输入最多 " << ArSize
         << " 条短语（输入空行结束）：\n";
    String sayings[ArSize];     // 对象数组
    char temp[MaxLen];          // 临时字符串存储
    int i;
    for (i = 0; i < ArSize; i++)
    {
        cout << i+1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n')
            continue;
        if (!cin || temp[0] == '\0')    // 是空行吗？
            break;              // i 不递增
        else
            sayings[i] = temp;  // 重载赋值运算符
    }
    int total = i;             // 读取的总行数

    if (total > 0)
    {
        cout << "这是你输入的短语：\n";
        for (i = 0; i < total; i++)
            cout << sayings[i] << "\n";

        // 使用指针来跟踪最短的和字母顺序第一的字符串
        String * shortest = &sayings[0]; // 初始化为第一个对象
        String * first = &sayings[0];
        for (i = 1; i < total; i++)
        {
            if (sayings[i].length() < shortest->length())
                shortest = &sayings[i];
            if (sayings[i] < *first)     // 比较值
                first = &sayings[i];     // 赋值地址
        }
        cout << "最短的短语：\n" << *shortest << endl;
        cout << "按字母顺序排第一的短语：\n" << *first << endl;

        srand(time(0));
        int choice = rand() % total;     // 随机选择一个索引
        // 使用 new 创建并初始化新的 String 对象
        String * favorite = new String(sayings[choice]);
        cout << "我最喜欢的短语：\n" << *favorite << endl;
        delete favorite;
    }
    else
        cout << "没什么要说的吗？\n";
    cout << "再见。\n";
    return 0;
}
