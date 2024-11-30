// strquote.cpp -- 不同的设计方案
#include <string>
#include <iostream>
using namespace std;

string version1(const string & s1, const string & s2);
const string & version2(string & s1, const string & s2);  // 有副作用
const string & version3(string & s1, const string & s2);  // 糟糕的设计

int main()
{
    string input;    // 输入字符串
    string copy;     // 输入的副本
    string result;   // 结果字符串

    cout << "请输入一个字符串: ";
    getline(cin, input);
    copy = input;    // 保存原始输入的副本
    cout << "您输入的字符串是: " << input << endl;
    result = version1(input, "***");
    cout << "修饰后的字符串: " << result << endl;
    cout << "原始字符串: " << input << endl;

    result = version2(input, "###");
    cout << "修饰后的字符串: " << result << endl;
    cout << "原始字符串: " << input << endl;

    cout << "重置原始字符串。\n";
    input = copy;
    result = version3(input, "@@@");
    cout << "修饰后的字符串: " << result << endl;
    cout << "原始字符串: " << input << endl;

    return 0;
}

// 版本1：返回一个新字符串
string version1(const string & s1, const string & s2)
{
    string temp;
    temp = s2 + s1 + s2;    // 在字符串两端添加修饰
    return temp;
}

// 版本2：修改原字符串并返回引用
const string & version2(string & s1, const string & s2)   // 有副作用
{
    s1 = s2 + s1 + s2;      // 修改原字符串
    return s1;
}

// 版本3：错误的设计
const string & version3(string & s1, const string & s2)   // 糟糕的设计
{
    string temp;
    temp = s2 + s1 + s2;    // 危险！返回局部变量的引用
    return temp;
}
