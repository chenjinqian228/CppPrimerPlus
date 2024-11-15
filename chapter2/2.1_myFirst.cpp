// myfirst.cpp -- displays a message        // 这是程序的注释，说明程序的用途
#include <iostream>                         // 包含输入输出流头文件
int main()                                 // 主函数，程序的入口点
{                                          // 函数体开始
    std::cout << "Come up and C++ me some time."; // 输出第一行文字
    std::cout << std::endl;                          // 输出换行符
    std::cout << "You won't regret it!" << std::endl; // 输出第二行文字并换行
    std::cin.get();                              // 等待用户输入
    return 0;                              // 返回0表示程序正常结束
}                                          // 函数体结束
