// recur.cpp -- 使用递归
#include <iostream>
void countdown(int n);

int main()
{
    countdown(4);    // 调用递归函数
    return 0;
}

void countdown(int n)
{
    using namespace std;
    cout << "倒计时中... " << n << "(n at "<< &n << ")"<< endl;
    if (n > 0)
    {
        countdown(n-1);    // 函数调用自身
        cout << n << ": 轰隆！\n";
    }
}
