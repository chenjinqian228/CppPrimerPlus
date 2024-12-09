// queue.cpp -- 队列和顾客类方法的实现
#include "12.10_queue.h"
#include <cstdlib>      // 用于 rand() 函数，也可使用 stdlib.h

// 顾客类方法
void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;    // 生成1-3之间的随机处理时间
    arrive = when;                        // 设置到达时间
}

// 队列类方法
Queue::Queue(int qs) : qsize(qs)         // 构造函数，初始化队列大小
{
    front = rear = nullptr;    // 初始化首尾指针为空（也可用 nullptr）
    items = 0;             // 初始化项目数量为0
}

Queue::~Queue()            // 析构函数
{
    Node * temp;
    while (front != nullptr)   // 当队列非空时循环
    {
        temp = front;       // 保存队首节点地址
        front = front->next;// 将首指针移到下一个节点
        delete temp;        // 删除之前的队首节点
    }
}

bool Queue::isempty() const    // 检查队列是否为空
{
    return items == 0;
}

bool Queue::isfull() const     // 检查队列是否已满
{
    return items == qsize;
}

int Queue::queuecount() const  // 返回队列中的项目数量
{
    return items;
}

// 将项目添加到队列中
bool Queue::enqueue(const Item & item)
{
    if (isfull())             // 如果队列已满，返回false
        return false;
    Node * add = new Node;    // 创建新节点
    add->item = item;         // 设置节点数据
    add->next = nullptr;         // 新节点的下一个指针设为空
    items++;                  // 项目数加1
    if (front == nullptr)        // 如果队列为空
        front = add;          // 新节点成为队首
    else
        rear->next = add;     // 否则将新节点链接到队尾
    rear = add;               // 更新队尾指针
    return true;
}

// 从队列中移除项目
bool Queue::dequeue(Item & item)
{
    if (isempty())           // 如果队列为空，返回false
        return false;
    item = front->item;      // 获取队首项目
    items--;                 // 项目数减1
    Node * temp = front;     // 保存队首节点地址
    front = front->next;     // 更新队首指针
    delete temp;             // 删除原队首节点
    if (items == 0)          // 如果队列变空
        rear = nullptr;         // 将队尾指针置空
    return true;
}
