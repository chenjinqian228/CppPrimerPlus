// getinfo.cpp -- 输入和输出
#include <iostream>

int main()
{
    using namespace std;

    int carrots;

    cout << "你有多少个胡萝卜？" << endl;
    cin >> carrots;                    // C++输入
    cout << "这里再给你两个。 ";
    carrots = carrots + 2;
    // 下一行连接输出内容
    cout << "现在你有 " << carrots << " 个胡萝卜。" << endl;
    return 0;
}
