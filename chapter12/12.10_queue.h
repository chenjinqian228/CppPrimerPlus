// queue.h -- 队列的接口
#ifndef QUEUE_H_
#define QUEUE_H_

// 这个队列将包含 Customer（顾客）项
class Customer
{
private:
    long arrive;        // 顾客到达时间
    int processtime;    // 顾客处理时间
public:
    Customer() : arrive(0), processtime(0) {}
    void set(long when);
    long when() const { return arrive; }      // 返回到达时间
    int ptime() const { return processtime; } // 返回处理时间
};

typedef Customer Item;  // 将 Customer 类型定义为 Item

class Queue
{
private:
    // 类作用域定义
    // Node 是一个嵌套的结构体定义，局部于这个类
    struct Node { Item item; struct Node * next; };
    enum {Q_SIZE = 10};  // 默认队列大小
    // 私有类成员
    Node * front;        // 指向队列头部的指针
    Node * rear;         // 指向队列尾部的指针
    int items;           // 队列当前项目数量
    const int qsize;     // 队列最大项目数量
    // 预防性定义，防止公有复制
    Queue(const Queue & q) : qsize(0) { }            // 复制构造函数
    Queue & operator=(const Queue & q) { return *this; }  // 赋值运算符
public:
    Queue(int qs = Q_SIZE);    // 创建一个限制为 qs 的队列
    ~Queue();                  // 析构函数
    bool isempty() const;      // 检查队列是否为空
    bool isfull() const;       // 检查队列是否已满
    int queuecount() const;    // 返回队列中的项目数量
    bool enqueue(const Item &item);  // 在队尾添加项目
    bool dequeue(Item &item);        // 从队首移除项目
};
#endif
