// mixtypes.cpp -- 各种类型组合的示例
#include <iostream>

// 定义一个表示南极年份数据的结构体
struct antarctica_years_end
{
    int year;  // 年份
    /* 一些其他很有趣的数据等等 */
};

int main()
{
    // 创建三个结构体变量
    antarctica_years_end s01, s02, s03;
    s01.year = 1998;  // 给第一个结构体的year成员赋值

    // 创建一个指向结构体的指针，并指向s02
    antarctica_years_end * pa = &s02;
    pa->year = 1999;  // 通过指针设置year的值

    // 创建一个包含3个结构体的数组
    antarctica_years_end trio[3];
    trio[0].year = 2003;  // 设置数组第一个元素的year值
    std::cout << trio->year << std::endl;  // 输出数组第一个元素的year值

    // 创建一个指针数组，存放三个结构体的地址
    const antarctica_years_end * arp[3] = {&s01, &s02, &s03};
    std::cout << arp[1]->year << std::endl;  // 输出第二个指针指向的结构体的year值

    // 创建一个指向指针数组的指针
    const antarctica_years_end ** ppa = arp;
    // 使用C++11的自动类型推导
    auto ppb = arp;  // 编译器会自动推导ppb的类型
    // 或者可以显式声明：const antarctica_years_end ** ppb = arp;

    // 通过多重指针访问数据
    std::cout << (*ppa)->year << std::endl;    // 输出第一个指针指向的结构体的year值
    std::cout << (*(ppb+1))->year << std::endl;  // 输出第二个指针指向的结构体的year值
    
    return 0;
}
