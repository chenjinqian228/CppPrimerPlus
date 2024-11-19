// structur.cpp -- 一个简单的结构体示例
#include <iostream>
#include <string>
using namespace std;

struct inflatable // 结构体声明
{
    string name; // 名称
    float volume;    // 体积
    double price;    // 价格
};

int main()
{
    inflatable guest =
        {
            "光荣的格洛丽亚", // name的值
            1.88,             // volume的值
            29.99             // price的值
        }; // guest是一个inflatable类型的结构体变量
           // 初始化为指定的值
    inflatable pal =
        {
            "大胆的亚瑟",
            3.12,
            32.99}; // pal是第二个inflatable类型的结构体变量
    // 注意：某些编译器实现可能需要使用
    // static inflatable guest =

    cout << "扩展您的嘉宾名单，加入" << guest.name;
    cout << "和" << pal.name << "!\n";
    // pal.name是pal变量的name成员
    cout << "两位嘉宾的总价为$";
    cout << guest.price + pal.price << "!\n";
    return 0;
}
