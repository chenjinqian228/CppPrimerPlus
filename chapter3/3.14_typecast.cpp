// typecast.cpp --强制类型转换

#include <iostream>
int main()
{
    using namespace std;
    int auks, bats, coots;

    // 以下语句将值作为double相加，然后将结果转换为int
    auks = 19.99 + 11.99;

    // 这些语句将值作为int相加
    bats = (int) 19.99 + (int) 11.99;    // 旧的C语法
    coots = int (19.99) + int (11.99);   // 新的C++语法

    cout << "auks = " << auks << ", bats = " << bats;
    cout << ", coots = " << coots << endl;

    char ch = 'Z';
    cout << "The code for " << ch << " is ";    // 作为char打印
    cout << int(ch) << endl;                    // 作为int打印
    cout << "Yes, the code is ";
    cout << static_cast<int>(ch) << endl;       // 使用static_cast

    return 0;
}
