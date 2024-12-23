//nested.cpp -- 使用带有嵌套类的队列
// 这个程序演示了如何使用模板类QueueTP来实现一个简单的队列系统
#include <iostream>
#include <string>
#include "15.5_queuetp.h"

int main()
{
    using std::string;
    using std::cin;
    using std::cout;

    // 创建一个容量为5的字符串队列
    QueueTP<string> cs(5);
    string temp;

    // 当队列未满时,持续接收用户输入的姓名
    while (!cs.isfull())
    {
        cout << "请输入您的姓名。我们将按照到达顺序为您服务。\n姓名: ";
        getline(cin, temp);
        cs.enqueue(temp);  // 将姓名加入队列
    }
    cout << "队列已满。开始处理！\n";

    // 当队列非空时,依次处理队列中的姓名
    while (!cs.isempty())
    {
        cs.dequeue(temp);  // 从队列中取出姓名
        cout << "正在处理 " << temp << "...\n";
    }
    cout << "队列为空。\n";
    return 0;
}