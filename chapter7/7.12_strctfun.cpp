// strctfun.cpp -- 演示带结构体参数的函数
#include <iostream>
#include <cmath>

// 结构体声明
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
polar rect_to_polar(rect xypos);    // 直角坐标转换为极坐标
void show_polar(polar dapos);       // 显示极坐标

int main()
{
    using namespace std;
    rect rplace;        // 直角坐标
    polar pplace;       // 极坐标

    cout << "请输入 x 和 y 的值: ";
    while (cin >> rplace.x >> rplace.y)  // 巧妙使用cin
    {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "请输入下一组数字 (输入q退出): ";
    }
    cout << "程序结束.\n";
    return 0;
}

// 将直角坐标转换为极坐标
polar rect_to_polar(rect xypos)
{
    using namespace std;
    polar answer;

    // 计算距离：使用勾股定理
    answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
    // 计算角度：使用反正切函数
    answer.angle = atan2(xypos.y, xypos.x);
    return answer;     // 返回极坐标结构体
}

// 显示极坐标，将弧度转换为角度
void show_polar (polar dapos)
{
    using namespace std;
    const double Rad_to_deg = 57.29577951;    // 弧度转角度的转换系数

    cout << "距离 = " << dapos.distance;
    cout << ", 角度 = " << dapos.angle * Rad_to_deg;
    cout << " 度\n";
}
