// get_fun.cpp -- 演示 get() 和 getline() 的使用
#include <iostream>
const int Limit = 255;    // 定义输入缓冲区的最大长度

int main()
{
    using std::cout;      // 使用标准输出
    using std::cin;       // 使用标准输入
    using std::endl;      // 使用标准换行符

    char input[Limit];    // 声明字符数组用于存储输入

    cout << "请输入一个字符串用于 getline() 处理：\n";
    cin.getline(input, Limit, '#');    // 读取直到遇到'#'字符
    cout << "您输入的内容是：\n";
    cout << input << "\n第一阶段完成\n";

    char ch;             // 声明单个字符变量
    cin.get(ch);        // 读取下一个字符
    cout << "下一个输入字符是 " << ch << endl;

    if (ch != '\n')
        cin.ignore(Limit, '\n');    // 丢弃该行剩余的内容

    cout << "请输入一个字符串用于 get() 处理：\n";
    cin.get(input, Limit, '#');     // 使用 get() 读取字符串直到遇到'#'
    cout << "您输入的内容是：\n";
    cout << input << "\n第二阶段完成\n";

    cin.get(ch);        // 再次读取一个字符
    cout << "下一个输入字符是 " << ch << endl;

    return 0;
}
