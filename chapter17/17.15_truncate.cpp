// truncate.cpp -- 使用 get() 在必要时截断输入行
#include <iostream>
const int SLEN = 10;                                    // 定义字符数组最大长度为10
inline void eatline() { while (std::cin.get() != '\n') continue; }  // 内联函数：清除输入缓冲区中的剩余字符

int main()
{
    using std::cin;     // 使用标准输入
    using std::cout;    // 使用标准输出
    using std::endl;    // 使用标准换行符

    char name[SLEN];    // 声明存储名字的字符数组
    char title[SLEN];   // 声明存储头衔的字符数组
    cout << "请输入您的姓名：";           // 提示输入名字
    cin.get(name, SLEN);                   // 读取名字，最多读取SLEN-1个字符
    if (cin.peek() != '\n')               // 检查下一个字符是否是换行符
        cout << "抱歉，我们只能容纳 "  // 如果不是换行符，说明输入被截断
             << name << endl;              // 显示警告信息
    eatline();                            // 清除输入行中剩余的字符

    cout << "尊敬的 " << name << "，请输入您的头衔：\n";  // 提示输入头衔
    cin.get(title, SLEN);                 // 读取头衔，最多读取SLEN-1个字符
    if (cin.peek() != '\n')               // 检查下一个字符是否是换行符
        cout << "我们不得不截断您的头衔。\n";  // 如果不是换行符，说明头衔被截断
    eatline();                            // 清除输入行中剩余的字符

    cout << " 姓名：" << name             // 显示最终结果
         << "\n头衔：" << title << endl;  // 显示名字和头衔

    return 0;
}
