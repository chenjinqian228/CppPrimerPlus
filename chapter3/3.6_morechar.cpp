#include <iostream>

int main()
{
    using namespace std;
    char ch = 'M';        // 将字符 'M' 赋值给 ch
    int i = ch;           // 将字符的 ASCII 码值赋值给 i
    cout << "字符 " << ch << " 的 ASCII 码是 " << i << endl;

    cout << "将字符码加1：" << endl;
    ch = ch + 1;          // 改变字符
    i = ch;               // 获取新字符的ASCII码值
    cout << "字符 " << ch << " 的 ASCII 码是 " << i << endl;

    //使用 cout.put() 成员函数显示字符
    cout << "使用 cout.put(ch) 显示字符 ch: ";
    cout.put(ch);
    // 使用 cout.put() 显示 char 常量
    cout.put('!');
    cout << endl << "程序结束" << endl;
    return 0;
}
