// sqrt.cpp -- 使用 sqrt() 函数

#include <iostream>
#include <cmath>      // 或者使用 math.h

int main()
{
    using namespace std;

    double area;
    cout << "请输入你家的面积（单位：平方英尺）：";
    cin >> area;
    double side;
    side = sqrt(area);
    cout << "这相当于一个边长为 " << side
         << " 英尺的正方形。" << endl;
    cout << "真有趣！" << endl;
    return 0;
}
