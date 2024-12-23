// check_it.cpp -- 检查有效输入
#include <iostream>

int main()
{
    using namespace std;
    cout << "请输入数字: ";
    
    int sum = 0;        // 定义总和变量并初始化为0
    int input;          // 定义输入变量
    while (cin >> input)    // 当输入有效时继续循环
    {
        sum += input;   // 将输入的数字加到总和中
    }
    
    cout << "最后输入的值 = " << input << endl;
    cout << "总和 = " << sum << endl;
    return 0;
}
