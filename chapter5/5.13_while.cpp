// while.cpp -- 介绍 while 循环的使用
#include <iostream>
const int ArSize = 20;    // 定义字符数组的大小
int main()
{
    using namespace std;
    char name[ArSize];    // 创建一个可以存储20个字符的数组
    
    cout << "请输入您的名字：";
    cin >> name;
    cout << "下面是您的名字，按字符垂直显示并给出ASCII码值：\n";
    
    int i = 0;                     // 从字符串的开始处开始
    while (name[i] != '\0')        // 处理到字符串的结尾（空字符）
    {
        cout << name[i] << ": " << int(name[i]) << endl;  // 打印字符及其ASCII码值
        i++;                       // 不要忘记这一步，移动到下一个字符
    }
    return 0;
}
