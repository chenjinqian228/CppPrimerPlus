// bigstep.cpp -- 按指定数值计数
#include <iostream>

int main()
{
    using std::cout;      // using 声明，简化输出语句的写法
    using std::cin;       // 简化输入语句的写法
    using std::endl;      // 简化换行符的写法
    
    cout << "请输入一个整数: ";    // 提示用户输入
    int by;                        // 声明步进值变量
    cin >> by;                     // 获取用户输入的值
    cout << "按 " << by << " 进行计数:\n";
    
    // for循环：从0开始，每次增加by，直到达到100
    for (int i = 0; i < 100; i = i + by)
        cout << i << endl;         // 输出当前值并换行
        
    return 0;
}
