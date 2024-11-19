// 为什么指针还需要指定类型？
// 1内存访问范围：
// 指针运算：
// 数据解释方式：
#include <iostream>
using namespace std;

int main() {
    // 分配内存
    int* pi = new int;
    char* pc = new char;
    double* pd = new double;
    
    // 都存储数值65
    *pi = 65;
    *pc = 65;
    *pd = 65.0;
    
    // 输出地址（都是16进制）
    cout << "int指针地址: " << (void*)pi << endl;
    cout << "char指针地址: " << (void*)pc << endl;
    cout << "double指针地址: " << (void*)pd << endl;
    
    // 输出值（解释方式不同）
    cout << "int值: " << *pi << endl;      // 输出: 65
    cout << "char值: " << *pc << endl;     // 输出: A (ASCII 65)
    cout << "double值: " << *pd << endl;   // 输出: 65.0
    
    // 指针运算
    pi++;  // 移动4字节
    pc++;  // 移动1字节
    pd++;  // 移动8字节
    
    cout << "\n移动后的地址:" << endl;
    cout << "int指针地址: " << (void*)pi << endl;
    cout << "char指针地址: " << (void*)pc << endl;
    cout << "double指针地址: " << (void*)pd << endl;
    
    // 清理内存
    delete pi;
    delete pc;
    delete pd;
    
    return 0;
}
