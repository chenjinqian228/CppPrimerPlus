// strin.cpp -- 从字符数组中格式化读取
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    using namespace std;
    string lit = "这 是 一 个 漆 黑 的 暴 风 雨 天， "
                 "明月却光芒四射。";
    istringstream instr(lit);    // 将字符串用作输入缓冲区
    string word;
    while (instr >> word)        // 每次读取一个词
        cout << word << endl;
    return 0;
}
