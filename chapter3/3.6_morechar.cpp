#include <iostream>

int main()
{
    using namespace std;
    char ch = 'M';
    int i = ch;
    cout << "The ASCII code for " << ch << " is " << i << endl;

    cout << "Add one to the character code:" << endl;
    ch = ch + 1;
    i = ch;
    cout << "The ASCII code for " << ch << " is " << i << endl;

    //使用 cout.put() 成员函数显示字符
    cout << "Displaying char ch using cout.put(ch): ";
    cout.put(ch);
    // 使用 cout.put() 显示 char 常量
    cout.put('!');
    cout << endl << "Done" << endl;
    return 0;
}