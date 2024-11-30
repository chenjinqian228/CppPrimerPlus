// file2.cpp -- 包含被 file1.cpp 调用的函数
#include <iostream>
#include <cmath>
#include "coordin.h" // 结构模板和函数原型

// 将直角坐标转换为极坐标
polar rect_to_polar(rect xypos)
{
    using namespace std;
    polar answer;      // 定义返回值变量

    // 计算距离（使用勾股定理：距离 = √(x² + y²)）
    answer.distance = 
        sqrt( xypos.x * xypos.x + xypos.y * xypos.y);
    
    // 计算角度（使用 atan2 函数计算反正切值）
    answer.angle = atan2(xypos.y, xypos.x);
    
    return answer;      // 返回极坐标结构
}

// 显示极坐标，并将角度从弧度转换为度
void show_polar (polar dapos)
{
    using namespace std;
    // 弧度转角度的转换系数（180/π）
    const double Rad_to_deg = 57.29577951;

    cout << "距离 = " << dapos.distance;
    cout << ", 角度 = " << dapos.angle * Rad_to_deg;
    cout << " 度\n";
}
