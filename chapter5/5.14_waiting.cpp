// waiting.cpp -- 在延时循环中使用 clock() 函数
#include <iostream>
#include <ctime>    // 包含 clock() 函数和 clock_t 类型的定义
int main()
{
    using namespace std;
    cout << "请输入延迟时间（以秒为单位）：";
    float secs;     // 存储用户输入的秒数
    cin >> secs;
    
    // 将秒转换为系统时钟计时单位
    // CLOCKS_PER_SEC 是每秒的时钟计时次数（通常为1000）
    clock_t delay = secs * CLOCKS_PER_SEC;    
    
    cout << "开始计时\a\n";        // \a 是警报字符，会发出蜂鸣声
    clock_t start = clock();      // 记录开始时间
    
    while (clock() - start < delay)   // 等待，直到经过指定的时间
        ;                             // 空语句，注意这个分号
        
    cout << "计时结束 \a\n";          // 再次发出蜂鸣声
    return 0;
}
