// strtype3.cpp -- 更多string类的特性演示
#include <iostream>
#include <string>      // 引入string类
#include <cstring>     // 引入C风格字符串库
int main()
{
    using namespace std;
    char charr1[20];           // 创建一个长度为20的字符数组
    char charr2[20] = "jaguar"; // 创建并初始化一个字符数组
    string str1;               // 创建一个空的string对象
    string str2 = "panther";   // 创建并初始化一个string对象

    // string对象和字符数组的赋值操作
    str1 = str2;               // 将str2复制给str1
    strcpy(charr1, charr2);    // 将charr2复制给charr1

    // string对象和字符数组的追加操作
    str1 += " paste";          // 在str1末尾添加" paste"
    strcat(charr1, " juice");  // 在charr1末尾添加" juice"

    // 获取string对象和C风格字符串的长度
    int len1 = str1.size();    // 获取str1的长度
    int len2 = strlen(charr1); // 获取charr1的长度

    cout << "字符串 " << str1 << " 包含 "
         << len1 << " 个字符。\n";
    cout << "字符串 " << charr1 << " 包含 "
         << len2 << " 个字符。\n";

    return 0;
}
