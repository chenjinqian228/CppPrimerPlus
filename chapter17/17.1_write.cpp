// write.cpp -- 使用 cout.write() 的示例
#include <iostream>
#include <cstring> // 或者使用 string.h

int main()
{
    using std::cout;
    using std::endl;

    // 定义三个字符串常量指针
    const char *state1 = "Florida";  // 佛罗里达
    const char *state2 = "Kansas";   // 堪萨斯
    const char *state3 = "Euphoria"; // 欣快感
    int len = std::strlen(state2);   // 获取 state2 的字符串长度

    cout << "递增循环索引：\n";
    int i;
    // 递增循环：每次显示更多字符
    for (i = 1; i <= len; i++)
    {
        cout.write(state2, i); // 输出 state2 的前 i 个字符
        cout << endl;
    }

    // 连接输出
    cout << "递减循环索引：\n";
    // 递减循环：每次显示更少字符
    for (i = len; i > 0; i--)
        cout.write(state2, i) << endl; // 输出 state2 的前 i 个字符

    // 超出字符串长度
    cout << "超出字符串长度：\n";
    cout.write(state2, len + 5) << endl; // 尝试输出比实际长度多5个字符
    
    long val = 560031841;
    cout.write((char *)&val, sizeof val); // 输出 val 的二进制表示
    cout << endl;

    return 0;
}
