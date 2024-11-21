// formore.cpp -- 更多的 for 循环示例
#include <iostream>
const int ArSize = 16;    // 外部声明示例，定义数组大小

int main()
{
    // 声明一个长整型数组来存储阶乘结果
    long long factorials[ArSize];
    
    // 初始化：0!和1!都等于1
    factorials[1] = factorials[0] = 1LL;
    
    // 第一个循环：计算2!到15!的值
    for (int i = 2; i < ArSize; i++)
        factorials[i] = i * factorials[i-1];
    
    // 第二个循环：打印所有阶乘结果
    for (int i = 0; i < ArSize; i++)
        std::cout << i << "! = " << factorials[i] << std::endl;
        
    return 0;
}
