// stonewt.h -- Stonewt类的定义
#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt  // 英制重量类
{
private:
    enum {lbs_per_stn = 14};     // 一石等于14磅
    int stone;                    // 整数部分（以石为单位）
    double pds_left;             // 剩余的磅数（小数部分）
    double pounds;               // 总重量（以磅为单位）
public:
    Stonewt(double lbs);         // 构造函数，参数为磅
    Stonewt(int stn, double lbs);// 构造函数，参数为石和磅
    Stonewt();                   // 默认构造函数
    ~Stonewt();                  // 析构函数

    void show_lbs() const;       // 以磅为单位显示重量
    void show_stn() const;       // 以石为单位显示重量
};
#endif
