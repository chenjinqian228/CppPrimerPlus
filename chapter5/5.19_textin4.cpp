// textin4.cpp -- 使用 cin.get() 读取字符
#include <iostream>
int main(void)
{
    using namespace std;
    int ch;                     // 应该使用int类型，而不是char类型
    int count = 0;             // 计数器初始化为0

    while ((ch = cin.get()) != EOF) // 测试是否到达文件末尾
    {
        cout.put(char(ch));    // 将字符输出到屏幕
        ++count;               // 字符计数加1
    }
    cout << endl << count << " 个字符被读取\n";
    return 0;
}
