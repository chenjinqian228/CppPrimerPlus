// fill.cpp -- 更改字段的填充字符
#include <iostream>

int main()
{
    using std::cout;
    // 设置填充字符为星号
    cout.fill('*');
    // 定义包含两个员工姓名的字符串数组
    const char * staff[2] = { "Waldo Whipsnade", "Wilmarie Wooper"};
    // 定义对应的奖金数组
    long bonus[2] = {900, 1350};

    // 循环输出每个员工的信息
    for (int i = 0; i < 2; i++)
    {
        // 输出员工姓名和金额符号
        cout << staff[i] << ": $";
        // 设置下一个输出的宽度为7
        cout.width(7);
        // 输出奖金金额，如果位数不足7位，将用星号填充
        cout << bonus[i] << "\n";
    }

    return 0;
}
