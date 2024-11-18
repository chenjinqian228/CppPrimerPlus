// carrots.cpp -- 食品处理程序
// 使用并显示一个变量

#include <iostream>

int main()
{
    using namespace std;

    int carrots;            // 声明一个整型变量

    carrots = 25;          // 给变量赋值
    cout << "我有 ";
    cout << carrots;       // 显示变量的值
    cout << " 个胡萝卜。";
    cout << endl;
    carrots = carrots - 1; // 修改变量
    cout << "咔嚓，咔嚓。现在我有 " << carrots << " 个胡萝卜。" << endl;
    return 0;
}
