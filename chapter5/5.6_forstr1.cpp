// forstr1.cpp -- 使用 for 循环处理字符串
#include <iostream>     // 输入输出流
#include <string>       // 字符串类
int main()
{
    using namespace std;    // 使用标准命名空间
    cout << "请输入一个单词: ";
    string word;           // 声明字符串变量
    cin >> word;          // 获取用户输入的单词
    
    // 按反序显示字母
    for (int i = word.size() - 1; i >= 0; i--)  // 从最后一个字符开始
        cout << word[i];   // 输出当前位置的字符
    cout << "\n再见。\n";  // 输出结束语
    return 0;
}
