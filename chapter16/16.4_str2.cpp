// str2.cpp -- 演示 capacity()容量 和 reserve()预留空间 函数的使用
#include <iostream>
#include <string>

int main()
{
    using namespace std;
    
    // 定义三个字符串
    string empty;                                     // 空字符串
    string small = "bit";                            // 小字符串
    string larger = "Elephants are a girl's best friend";  // 较大的字符串
    
    // 输出各个字符串的大小
    cout << "字符串大小：\n";
    cout << "\tempty字符串: " << empty.size() << endl;
    cout << "\tsmall字符串: " << small.size() << endl;
    cout << "\tlarger字符串: " << larger.size() << endl;
    
    // 输出各个字符串的容量
    cout << "字符串容量：\n";
    cout << "\tempty字符串: " << empty.capacity() << endl;
    cout << "\tsmall字符串: " << small.capacity() << endl;
    cout << "\tlarger字符串: " << larger.capacity() << endl;
    
    // 为空字符串预留50个字符的空间
    empty.reserve(50);
    cout << "为空字符串预留50个字符后的容量: "
         << empty.capacity() << endl;
         
    return 0;
}
