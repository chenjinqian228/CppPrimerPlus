// arith.cpp -- C++算术运算示例
#include <iostream>
int main()
{
    using namespace std;
    float hats, heads;    // 声明两个浮点数变量
    
    cout.setf(ios_base::fixed, ios_base::floatfield); // 设置固定小数点格式
    cout << "请输入一个数字: ";
    cin >> hats;
    cout << "请输入另一个数字: ";
    cin >> heads;
    
    // 展示各种算术运算
    cout << "hats = " << hats << "; heads = " << heads << endl;
    cout << "hats + heads = " << hats + heads << endl;  // 加法
    cout << "hats - heads = " << hats - heads << endl;  // 减法
    cout << "hats * heads = " << hats * heads << endl;  // 乘法
    cout << "hats / heads = " << hats / heads << endl;  // 除法
    return 0;
}
