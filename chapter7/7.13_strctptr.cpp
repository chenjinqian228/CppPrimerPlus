// strctptr.cpp -- 使用指向结构的指针作为函数参数
#include <iostream>
#include <cmath>

// 结构声明
struct polar
{
    double distance;      // 距离原点的距离
    double angle;         // 与原点的角度
};
struct rect
{
    double x;            // 距原点的水平距离
    double y;            // 距原点的垂直距离
};

// 函数原型
void rect_to_polar(const rect * pxy, polar * pda);
void show_polar(const polar * pda);

int main()
{
    using namespace std;
    rect rplace;
    polar pplace;

    cout << "请输入 x 和 y 的值：";
    while (cin >> rplace.x >> rplace.y)  // cin 的巧妙运用
    {
        rect_to_polar(&rplace, &pplace);    // 传递地址
        show_polar(&pplace);                // 传递地址
        cout << "请输入下一组数字（输入q退出）：";
    }
    cout << "程序结束！\n";
    return 0;
}

// 将直角坐标转换为极坐标
void rect_to_polar(const rect * pxy, polar * pda)
{
    using namespace std;
    pda->distance = sqrt(pxy->x * pxy->x + pxy->y * pxy->y);
    pda->angle = atan2(pxy->y, pxy->x);
}

// 显示极坐标，将弧度转换为角度
void show_polar(const polar * pda)
{
    using namespace std;
    const double Rad_to_deg = 57.29577951;  // 弧度转角度的转换系数

    cout << "距离 = " << pda->distance;
    cout << "，角度 = " << pda->angle * Rad_to_deg;
    cout << " 度\n";
}
