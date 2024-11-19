// arrayone.cpp -- 小整数数组
#include <iostream>
int main()
{
    using namespace std;
    int yams[3];      // 创建包含三个元素的数组
    yams[0] = 7;      // 为第一个元素赋值
    yams[1] = 8;
    yams[2] = 6;

    int yamcosts[3] = {20, 30, 5};  // 创建并初始化数组
    // 注意：如果你的C++编译器或转译器不能初始化
    // 这个数组，使用 static int yamcosts[3] 替代
    // int yamcosts[3]

    cout << "薯蓣总数 = ";
    cout << yams[0] + yams[1] + yams[2] << endl;
    cout << "包含 " << yams[1] << " 个薯蓣的包装每个薯蓣花费 ";
    cout << yamcosts[1] << " 美分。\n";
    
    int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
    total = total + yams[2] * yamcosts[2];
    cout << "薯蓣总开销为 " << total << " 美分。\n";

    cout << "\nyams数组的大小 = " << sizeof yams;
    cout << " 字节。\n";
    cout << "一个元素的大小 = " << sizeof yams[0];
    cout << " 字节。\n";

    return 0;
}
