// coordin.h -- 结构模板和函数原型
// 结构模板
#ifndef COORDIN_H_
#define COORDIN_H_

// 极坐标结构
struct polar
{
    double distance;    // 到原点的距离
    double angle;       // 从原点出发的角度
};

// 直角坐标结构
struct rect
{
    double x;          // 距原点的水平距离
    double y;          // 距原点的垂直距离
};

// 函数原型
polar rect_to_polar(rect xypos);    // 直角坐标转换为极坐标
void show_polar(polar dapos);    // 极坐标转换为直角坐标

#endif
