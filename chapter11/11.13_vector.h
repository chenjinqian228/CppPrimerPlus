#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>

namespace VECTOR
{
    class Vector
    {
    public:
        enum Mode {RECT, POL};
        // RECT表示直角坐标模式，POL表示极坐标模式
    private:
        double x;          // 水平分量
        double y;          // 垂直分量
        double mag;        // 向量长度（模）
        double ang;        // 向量方向（角度）
        Mode mode;         // 模式：RECT或POL
        // 用于设置各个分量的私有方法
        void set_mag();    // 设置向量长度
        void set_ang();    // 设置向量角度
        void set_x();      // 设置x分量
        void set_y();      // 设置y分量
    public:
        Vector();          // 默认构造函数
        // 构造函数：接受两个值和模式（默认为直角坐标）
        Vector(double n1, double n2, Mode form = RECT);
        // 重置向量值
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();         // 析构函数
        
        // 获取各个分量的值（const成员函数）
        double xval() const {return x;}       // 返回x分量
        double yval() const {return y;}       // 返回y分量
        double magval() const {return mag;}   // 返回向量长度
        double angval() const {return ang;}   // 返回向量角度
        
        void polar_mode();                    // 设置为极坐标模式
        void rect_mode();                     // 设置为直角坐标模式
        
        // 运算符重载
        Vector operator+(const Vector & b) const;  // 向量加法
        Vector operator-(const Vector & b) const;  // 向量减法
        Vector operator-() const;                  // 向量取反
        Vector operator*(double n) const;          // 向量数乘
        
        // 友元函数
        friend Vector operator*(double n, const Vector & a);  // 数乘（左乘）
        friend std::ostream & operator<<(std::ostream & os, const Vector & v);  // 输出运算符
    };
}   // 结束命名空间VECTOR
#endif
