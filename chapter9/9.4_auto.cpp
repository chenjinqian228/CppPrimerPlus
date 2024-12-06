// autoscp.cpp -- 演示自动变量的作用域
#include <iostream>
void oil(int x);

int main()
{
    using namespace std;

    int texas = 31;
    int year = 2011;
    cout << "在main()中, texas = " << texas << ", &texas = ";
    cout << &texas << endl;
    cout << "在main()中, year = " << year << ", &year = ";
    cout << &year << endl;
    oil(texas);
    cout << "在main()中, texas = " << texas << ", &texas = ";
    cout << &texas << endl;
    cout << "在main()中, year = " << year << ", &year = ";
    cout << &year << endl;
    return 0;
}

void oil(int x)
{
    using namespace std;
    int texas = 5;

    cout << "在oil()中, texas = " << texas << ", &texas = ";
    cout << &texas << endl;
    cout << "在oil()中, x = " << x << ", &x = ";
    cout << &x << endl;
    {                               // 开始一个代码块
        int texas = 113;           // 新变量
        cout << "在代码块中, texas = " << texas;
        cout << ", &texas = " << &texas << endl;
    }                              // 结束代码块
    cout << "代码块结束后 texas = " << texas;
    cout << ", &texas = " << &texas << endl;
}
