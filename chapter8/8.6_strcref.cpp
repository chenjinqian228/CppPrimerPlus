//strc_ref.cpp --使用结构引用
#include <iostream>
#include <cstring>

// 定义投篮数据结构
struct free_throws
{
    std::string name;    // 球员姓名
    int made;           // 投中次数
    int attempts;       // 投篮次数
    float percent;      // 命中率
};

void display(const free_throws & ft);            // 显示球员数据
void set_pc(free_throws & ft);                  // 计算命中率
free_throws & accumulate(free_throws & target, const free_throws & source);  // 累加数据

int main()
{
    // 部分初始化 - 剩余成员被设置为0
    free_throws one = {"Ifelsa Branch", 13, 14};
    free_throws two = {"Andor Knott", 10, 16};
    free_throws three = {"Minnie Max", 7, 9};
    free_throws four = {"Whily Looper", 5, 9};
    free_throws five = {"Long Long", 6, 14};
    free_throws team = {"Throwgoods", 0, 0};
    // 不进行初始化
    free_throws dup;

    set_pc(one);
    display(one);
    accumulate(team, one);
    display(team);
    // 使用返回值作为参数
    display(accumulate(team, two));
    accumulate(accumulate(team, three), four);
    display(team);
    // 使用返回值进行赋值
    dup = accumulate(team, five);
    std::cout << "显示球队数据:\n";
    display(team);
    std::cout << "赋值后显示dup的数据:\n";
    display(dup);
    set_pc(four);
    // 不恰当的赋值
    accumulate(dup,five) = four;
    std::cout << "不恰当赋值后显示dup的数据:\n";
    display(dup);
    return 0;
}

// 显示投篮数据
void display(const free_throws & ft)
{
    using std::cout;
    cout << "姓名: " << ft.name << "\n";
    cout << "投中: " << ft.made << "\n";
    cout << "尝试: " << ft.attempts << "\n";
    cout << "命中率: " << ft.percent << "\n";
}

// 计算命中率
void set_pc(free_throws & ft)
{
    if (ft.attempts != 0)
        ft.percent = 100.0f * ft.made / ft.attempts;
    else
        ft.percent = 0;
}

// 累加两个球员/球队的数据
free_throws & accumulate(free_throws & target, const free_throws & source)
{
    target.attempts += source.attempts;  // 累加投篮次数
    target.made += source.made;         // 累加投中次数
    set_pc(target);                     // 重新计算命中率
    return target;                      // 返回目标对象的引用
}
