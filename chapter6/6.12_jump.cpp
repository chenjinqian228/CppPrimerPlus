// jump.cpp -- 使用continue和break语句
#include <iostream>
const int ArSize = 80;    // 数组大小

int main()
{
    using namespace std;
    char line[ArSize];    // 字符数组，用于存储文本行
    int spaces = 0;       // 空格计数器

    cout << "请输入一行文本：\n";
    cin.get(line, ArSize);
    cout << "完整的文本行：\n" << line << endl;
    cout << "第一个句号之前的文本：\n";
    for (int i = 0; line[i] != '\0'; i++)
    {
        cout << line[i];      // 显示字符
        if (line[i] == '.')   // 如果是句号就退出
            break;
        if (line[i] != ' ')   // 如果不是空格就跳过循环剩余部分
            continue;
        spaces++;             // 空格计数加1
    }
    cout << "\n" << spaces << " 个空格\n";
    cout << "程序结束。\n";
    return 0;
}
