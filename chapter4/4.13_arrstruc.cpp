// arrstruc.cpp -- 结构体数组示例
#include <iostream>
struct inflatable
{
    char name[20];    // 名称
    float volume;     // 体积
    double price;     // 价格
};

int main()
{
    using namespace std;
    inflatable guests[2] =        // 初始化结构体数组
    {
        {"小鹿斑比", 0.5, 21.99},   // 数组中的第一个结构体
        {"哥斯拉", 2000, 565.99}    // 数组中的第二个结构体
    };

    cout << "来宾 " << guests[0].name << " 和 " << guests[1].name
         << "\n总共占据了 "
         << guests[0].volume + guests[1].volume << " 立方英尺的空间。\n";
    return 0;
}
