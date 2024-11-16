// arith.cpp -- 一些C++算术运算示例
#include <iostream>
int main()
{
    using namespace std;
    float hats, heads;
    
    cout.setf(ios_base::fixed, ios_base::floatfield); // 设置为固定小数点格式
    cout << "Enter a number: ";
    cin >> hats;
    cout << "Enter another number: ";
    cin >> heads;
    
    cout << "hats = " << hats << "; heads = " << heads << endl;
    cout << "hats + heads = " << hats + heads << endl;
    cout << "hats - heads = " << hats - heads << endl;
    cout << "hats * heads = " << hats * heads << endl;
    cout << "hats / heads = " << hats / heads << endl;
    return 0;
}
