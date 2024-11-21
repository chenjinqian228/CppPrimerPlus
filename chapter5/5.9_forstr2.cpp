// forstr2.cpp -- 数组反转程序
#include <iostream>
#include <string>
int main()
{
    using namespace std;
    cout << "请输入一个单词：";
    string word;        // 声明字符串变量
    cin >> word;        // 获取用户输入的单词
    
    // 直接修改字符串对象
    char temp;          // 临时变量，用于交换字符
    int i, j;          // i是从后往前的索引，j是从前往后的索引
    for (j = 0, i = word.size() - 1; j < i; --i, ++j)
    {                   // 代码块开始
        temp = word[i]; // 保存末尾字符
        word[i] = word[j]; // 将前面的字符移到后面
        word[j] = temp;    // 将末尾字符放到前面
    }                   // 代码块结束
    cout << word << "\n完成！\n";  // 输出反转后的结果
    return 0;
}
