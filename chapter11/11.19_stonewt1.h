// stonewt1.h -- Stonewt类的修订定义
#ifndef STONEWT1_H_
#define STONEWT1_H_

class Stonewt
{
private:
    enum {Lbs_per_stn = 14};    // 一石等于14磅
    int stone;                   // 整数部分（石）
    double pds_left;            // 剩余的磅数（小数部分）
    double pounds;              // 总重量（磅）
public:
    Stonewt(double lbs);        // 以磅为单位构造
    Stonewt(int stn, double lbs); // 以石和磅为单位构造
    Stonewt();                  // 默认构造函数
    ~Stonewt();                 // 析构函数
    void show_lbs() const;      // 以磅为单位显示重量
    void show_stn() const;      // 以石为单位显示重量
    // 类型转换函数
    operator int() const;       // 转换为整型
    operator double() const;    // 转换为双精度型
};

#endif
