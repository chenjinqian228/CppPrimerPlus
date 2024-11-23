// ifelseif.cpp -- 使用 if else if else 结构
#include <iostream>
const int Fave = 27;

int main()
{
    using namespace std;
    int n;
    
    cout << "请输入一个1-100之间的数字来猜测";
    cout << "我最喜欢的数字: ";
    do
    {
        cin >> n;
        if (n < Fave)
            cout << "太小了 -- 请重新猜: ";
        else if (n > Fave)
            cout << "太大了 -- 请重新猜: ";
        else
            cout << Fave << " 猜对了！\n";
    } while (n != Fave);
    
    return 0;
}
