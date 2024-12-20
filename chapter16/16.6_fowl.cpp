// fowl.cpp -- auto_ptr 是个糟糕的选择
#include <iostream>    // 输入输出流
#include <string>      // 字符串库
#include <memory>      // 智能指针库

int main()
{
    using namespace std;
    // 创建一个包含5个 auto_ptr<string> 的数组
    shared_ptr<string> films[5] = 
    {
        shared_ptr<string> (new string("禽球")),         // Fowl Balls (谐音 Foul Balls-界外球)
        shared_ptr<string> (new string("鸭子步行")),     // Duck Walks
        shared_ptr<string> (new string("鸡飞狗跳")),     // Chicken Runs
        shared_ptr<string> (new string("火鸡失误")),     // Turkey Errors
        shared_ptr<string> (new string("鹅蛋")),         // Goose Eggs (棒球比赛中的零分)
    };

    shared_ptr<string> pwin;
    pwin = films[2];    // films[2] 失去所有权 - 这里是问题所在！

    cout << "最佳禽类棒球电影提名是：\n";
    // 这个循环可能会导致程序崩溃，因为 films[2] 已经失去了所有权
    for (int i = 0; i < 5; i++)
        cout << *films[i] << endl;
    cout << "获奖者是 " << *pwin << "！\n";
    cin.get();         // 暂停程序
    return 0;
}
