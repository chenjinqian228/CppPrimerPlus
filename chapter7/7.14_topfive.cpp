// topfive.cpp -- 处理字符串对象数组
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5;

void display(const string sa[], int n);

int main()
{
    string list[SIZE];    // 一个包含5个字符串对象的数组
    cout << "请输入您最喜欢的" << SIZE << "个天文景观：\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << i + 1 << ": ";
        getline(cin, list[i]);
    }

    cout << "您的列表：\n";
    display(list, SIZE);

    return 0;
}

void display(const string sa[], int n)
{
    for (int i = 0; i < n; i++)
        cout << i + 1 << ": " << sa[i] << endl;
}
