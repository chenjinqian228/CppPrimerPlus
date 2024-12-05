// vect.cpp -- Vector类的方法实现
#include <cmath>
#include "11.13_vector.h" // 包含 <iostream>
using std::atan;
using std::atan2;
using std::cos;
using std::cout;
using std::sin;
using std::sqrt;

namespace VECTOR
{
    // 计算一弧度对应的角度
    const double Rad_to_deg = 45.0 / atan(1.0);
    // 约等于57.29577461

    // 私有方法
    // 根据x和y计算向量的长度
    void Vector::set_mag()
    {
        mag = sqrt(x * x + y * y);
    }

    // 计算向量的角度
    void Vector::set_ang()
    {
        if (x == 0.0 && y == 0.0)
            ang = 0.0;
        else
            ang = atan2(y, x);
    }

    // 根据极坐标设置x分量
    void Vector::set_x()
    {
        x = mag * cos(ang);
    }

    // 根据极坐标设置y分量
    void Vector::set_y()
    {
        y = mag * sin(ang);
    }

    // 公有方法
    Vector::Vector() // 默认构造函数
    {
        x = y = mag = ang = 0.0;
        mode = RECT;
    }

    // 构造函数
    // 如果form为RECT（默认值），则使用直角坐标构造
    // 如果form为POL，则使用极坐标构造
    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (form == POL)
        {
            mag = n1;
            ang = n2 / Rad_to_deg;    // 角度转换为弧度
            set_x();
            set_y();
        }
        else
        {
            cout << "Vector()的第三个参数错误 -- ";
            cout << "向量设置为0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }

    // 重置向量值
    // 如果form为RECT（默认值），则使用直角坐标
    // 如果form为POL，则使用极坐标
    void Vector::reset(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (form == POL)
        {
            mag = n1;
            ang = n2 / Rad_to_deg;    // 角度转换为弧度
            set_x();
            set_y();
        }
        else
        {
            cout << "Vector()的第三个参数错误 -- ";
            cout << "向量设置为0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }

    Vector::~Vector() // 析构函数
    {
    }

    void Vector::polar_mode() // 设置为极坐标模式
    {
        mode = POL;
    }

    void Vector::rect_mode() // 设置为直角坐标模式
    {
        mode = RECT;
    }

    // 运算符重载
    // 向量加法
    Vector Vector::operator+(const Vector &b) const
    {
        return Vector(x + b.x, y + b.y);
    }

    // 向量减法：从a减去向量b
    Vector Vector::operator-(const Vector &b) const
    {
        return Vector(x - b.x, y - b.y);
    }

    // 向量取反
    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }

    // 向量数乘（向量 * 数字）
    Vector Vector::operator*(double n) const
    {
        return Vector(n * x, n * y);
    }

    // 友元方法
    // 数乘（数字 * 向量）
    Vector operator*(double n, const Vector &a)
    {
        return a * n;
    }

    // 输出运算符重载
    // 如果mode为RECT则显示直角坐标
    // 如果mode为POL则显示极坐标
    std::ostream &operator<<(std::ostream &os, const Vector &v)
    {
        if (v.mode == Vector::RECT)
            os << "(x,y) = (" << v.x << ", " << v.y << ")";
        else if (v.mode == Vector::POL)
        {
            os << "(m,a) = (" << v.mag << ", "
               << v.ang * Rad_to_deg << ")";  // 弧度转换为角度
        }
        else
            os << "Vector对象的模式无效";
        return os;
    }
}
