// strings.cpp -- 在数组中存储字符串
#include <iostream>
#include <cstring>  // 用于strlen()函数

int main()
{
    using namespace std;
    const int Size = 15;
    char name1[Size];           // 空数组
    char name2[Size] = "C++owboy";  // 初始化的数组
    // 注意：某些编译器可能需要static关键字
    // 来初始化数组name2

    cout << "Howdy! I'm " << name2;
    cout << "! What's your name?\n";
    cin >> name1;
    cout << "Well, " << name1 << ", your name has ";
    cout << strlen(name1) << " letters and is stored\n";
    cout << "in an array of " << sizeof(name1) << " bytes.\n";
    cout << "Your initial is " << name1[0] << ".\n";
    name2[3]= '\0';           // 设置为空字符
    cout << "Here are the first 3 characters of my name: ";
    cout << name2 << endl;
    return 0;
}
