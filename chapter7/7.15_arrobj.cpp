// arrobj.cpp -- 使用数组对象的函数（C++11）
#include <iostream>
#include <array>
#include <string>

// 常量数据
const int Seasons = 4;
const std::array<std::string, Seasons> Snames = 
    {"春季", "夏季", "秋季", "冬季"};

// 修改数组对象的函数
void fill(std::array<double, Seasons> * pa);
// 使用数组对象但不修改它的函数
void show(std::array<double, Seasons> da);

int main()
{
    std::array<double, Seasons> expenses;
    fill(&expenses);
    show(expenses);
    return 0;
}

void fill(std::array<double, Seasons> * pa)
{
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << "请输入" << Snames[i] << "的支出：";
        std::cin >> (*pa)[i];
    }
}

void show(std::array<double, Seasons> da)
{
    double total = 0.0;
    std::cout << "\n支出明细\n";
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << Snames[i] << "：￥" << da[i] << '\n';
        total += da[i];
    }
    std::cout << "总支出：￥" << total << '\n';
}
