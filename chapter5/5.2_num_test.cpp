// num_test.cpp -- 在 for 循环中使用数值测试
#include <iostream>
int main()
{
    using namespace std;
    cout << "请输入起始倒计时值：";
    int limit;
    cin >> limit;
    int i;
    for (i = limit; i; i--)    // 当 i 为 0 时退出
        cout << "i = " << i << "\n";
    cout << "现在完成了，i = " << i << "\n";
    return 0;
}
