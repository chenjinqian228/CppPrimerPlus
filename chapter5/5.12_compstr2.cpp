// compstr2.cpp -- 使用数组比较字符串
#include <iostream>
#include <string>      // 引入string类
int main()
{
    using namespace std;
    string word = "?ate";    // 初始化字符串，第一个字符为问号
    
    // 从字符'a'开始，当word不等于"mate"时，字符不断递增
    for (char ch = 'a'; word != "mate"; ch++)
    {
        cout << word << endl;     // 打印当前字符串
        word[0] = ch;            // 修改字符串的第一个字符
    }
    // 循环结束后打印最终的字符串
    cout << "循环结束后，字符串word的值是 " << word << endl;
    return 0;
}
