// bank.cpp -- 使用Queue接口实现的银行ATM模拟程序
#include <iostream>
#include <cstdlib>  // 用于rand()和srand()函数
#include <ctime>    // 用于time()函数
#include "12.10_queue.h"
#include "12.11_queue.cpp"
const int MIN_PER_HR = 60;  // 每小时的分钟数

bool newcustomer(double x);  // 判断是否有新顾客到达

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    // 初始化设置
    std::srand(std::time(0));    // 随机数生成器初始化

    cout << "案例研究：希瑟银行自动取款机\n";
    cout << "请输入队列的最大长度：";
    int qs;
    cin >> qs;
    Queue line(qs);         // 创建最多容纳qs人的队列

    cout << "请输入模拟的小时数：";
    int hours;              // 模拟时间（小时）
    cin >> hours;
    // 模拟将每分钟运行一个循环
    long cyclelimit = MIN_PER_HR * hours; // 循环次数

    cout << "请输入每小时的平均顾客数：";
    double perhour;         // 每小时平均到达的顾客数
    cin >> perhour;
    double min_per_cust;    // 顾客到达的平均时间间隔
    min_per_cust = MIN_PER_HR / perhour;

    Item temp;              // 新顾客数据
    long turnaways = 0;     // 因队列已满而离开的顾客数
    long customers = 0;     // 加入队列的顾客总数
    long served = 0;        // 在模拟期间得到服务的顾客数
    long sum_line = 0;      // 累计的队列长度
    int wait_time = 0;      // 距离ATM空闲的时间
    long line_wait = 0;     // 累计的等待时间

    // 运行模拟
    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))  // 如果有新顾客到达
        {
            if (line.isfull())
                turnaways++;            // 队列已满，顾客离开
            else
            {
                customers++;            // 将顾客加入队列
                temp.set(cycle);        // cycle = 到达时间
                line.enqueue(temp);     // 将新顾客加入队列
            }
        }
        if (wait_time <= 0 && !line.isempty())
        {
            line.dequeue(temp);         // 下一位顾客得到服务
            wait_time = temp.ptime();   // 设置等待时间
            line_wait += cycle - temp.when(); // 计算此顾客的等待时间
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.queuecount();  // 累加当前队列长度
    }

    // 报告结果
    if (customers > 0)
    {
        cout << "接待的顾客数: " << customers << endl;
        cout << "服务的顾客数: " << served << endl;
        cout << "离开的顾客数: " << turnaways << endl;
        cout << "平均队列长度: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit << endl;
        cout << "平均等待时间: "
             << (double) line_wait / served << " 分钟\n";
    }
    else
        cout << "没有顾客！\n";
    cout << "完成模拟！\n";

    return 0;
}

// 根据概率返回是否有新顾客到达
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}
