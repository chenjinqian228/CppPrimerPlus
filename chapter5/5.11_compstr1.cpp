// compstr1.cpp -- 使用数组比较字符串的示例
#include <iostream>
#include <cstring>      // 包含strcmp()函数的原型声明
int main()
{
    using namespace std;
    // 定义一个长度为5的字符数组，初始化为"?ate"
    char word[5] = "?ate";
    // 从字符'a'开始，当word不等于"mate"时，继续循环并递增ch
    for (char ch = 'a'; strcmp(word, "mate"); ch++)
    {
        // 输出当前word的值
        cout << word << endl;
        // 修改word的第一个字符
        word[0] = ch;
    }
    // 输出循环结束时word的最终值
    cout << "循环结束后，word的值是 " << word << endl;
    return 0;
}
