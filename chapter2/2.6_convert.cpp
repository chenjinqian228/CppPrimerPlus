// convert.cpp -- 将英石转换为磅
#include <iostream>

int stonetolb(int);    // 函数原型

int main()
{
    using namespace std;
    int stone;
    cout << "请输入重量（英石）：";
    cin >> stone;
    int pounds = stonetolb(stone);
    cout << stone << " 英石 = ";
    cout << pounds << " 磅。" << endl;
    return 0;
}

int stonetolb(int sts)
{
    return 14 * sts;    // 1英石等于14磅
}