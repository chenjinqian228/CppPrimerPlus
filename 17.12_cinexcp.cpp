// cinexcp.cpp -- 让 cin 抛出异常的示例
#include <iostream>
#include <exception>

int main()
{
    using namespace std;
    // 设置failbit位导致异常被抛出
    cin.exceptions(ios_base::failbit);
    cout << "请输入数字: ";
    int sum = 0;        // 总和
    int input;          // 输入值
    try {
        while (cin >> input)     // 读取输入
        {
            sum += input;        // 累加输入的值
        }
    } catch(ios_base::failure & bf)  // 捕获输入流异常
    {
        cout << bf.what() << endl;   // 输出异常信息
        cout << "哦！太糟糕了！\n";    // 自定义错误信息
    }

    cout << "最后输入的值 = " << input << endl;
    cout << "总和 = " << sum << endl;
    return 0;
}
