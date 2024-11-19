// strtype4.cpp -- 行输入示例
#include <iostream>
#include <string>      // 使string类可用
#include <cstring>     // C风格字符串库
int main()
{
    using namespace std;
    char charr[20];    // 创建一个长度为20的字符数组
    string str;        // 创建一个string对象

    cout << "字符数组charr在输入前的长度: "
         << strlen(charr) << endl;
    cout << "字符串str在输入前的长度: "
         << str.size() << endl;
    cout << "请输入一行文本:\n";
    cin.getline(charr, 20);    // 指定最大输入长度为20
    cout << "你输入的是: " << charr << endl;
    cout << "请输入另一行文本:\n";
    getline(cin, str);         // cin现在是参数；不需要指定长度
    cout << "你输入的是: " << str << endl;
    cout << "字符数组charr在输入后的长度: "
         << strlen(charr) << endl;
    cout << "字符串str在输入后的长度: "
         << str.size() << endl;

    return 0;
}
