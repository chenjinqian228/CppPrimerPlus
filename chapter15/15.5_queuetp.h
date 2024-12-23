// queuetp.h -- 带有嵌套类的队列模板
#ifndef QUEUETP_H_
#define QUEUETP_H_

// QueueTP是一个队列的模板类,支持任意类型的元素存储
template <class Item>
class QueueTP
{
private:
    enum {Q_SIZE = 10};    // 默认队列大小为10
    // Node是一个嵌套类,用于表示队列中的节点
    class Node
    {
    public:
        Item item;         // 存储的数据
        Node * next;       // 指向下一个节点的指针
        Node(const Item & i) : item(i), next(0) { } // 构造函数初始化数据和指针
    };
    Node * front;          // 指向队列头部的指针
    Node * rear;           // 指向队列尾部的指针  
    int items;             // 队列当前的元素数量
    const int qsize;       // 队列可容纳的最大元素数量
    QueueTP(const QueueTP & q) : qsize(0) { }  // 禁用拷贝构造函数
    QueueTP & operator=(const QueueTP & q) { return *this; }  // 禁用赋值运算符
public:
    QueueTP(int qs = Q_SIZE);  // 构造函数,可指定队列大小
    ~QueueTP();                // 析构函数
    bool isempty() const       // 检查队列是否为空
    {
        return items == 0;
    }
    bool isfull() const        // 检查队列是否已满
    {
        return items == qsize;
    }
    int queuecount() const     // 返回队列中的元素个数
    {
        return items;
    }
    bool enqueue(const Item &item); // 在队尾添加元素
    bool dequeue(Item &item);       // 从队头移除元素
};

// QueueTP方法
template <class Item>
QueueTP<Item>::QueueTP(int qs) : qsize(qs)
{
    front = rear = 0;      // 初始化头尾指针为空
    items = 0;             // 初始化元素个数为0
}
template <class Item>
QueueTP<Item>::~QueueTP()
{
    Node * temp;
    while (front != 0)      // 当队列非空时
    {
        temp = front;       // 保存队头元素的地址
        front = front->next;// 重置指针指向下一个元素
        delete temp;        // 删除原来的队头元素
    }
}

// 向队列添加元素
template <class Item>
bool QueueTP<Item>::enqueue(const Item & item)
{
    if (isfull())          // 如果队列已满则返回false
        return false;
    Node * add = new Node(item);    // 创建新节点
    // 失败时，new会抛出std::bad_alloc异常
    items++;               // 增加元素计数
    if (front == 0)        // 如果队列为空
        front = add;       // 将元素放在队头
    else
        rear->next = add;  // 否则放在队尾
    rear = add;            // 让rear指向新节点
    return true;
}

// 将队头元素放入item变量并从队列中移除
template <class Item>
bool QueueTP<Item>::dequeue(Item & item)
{
    if (front == 0)        // 如果队列为空则返回false
        return false;
    item = front->item;    // 将item设置为队列中的第一个元素
    items--;               // 减少元素计数
    Node * temp = front;   // 保存第一个元素的位置
    front = front->next;   // 重置front指向下一个元素
    delete temp;           // 删除原来的第一个元素
    if (items == 0)        // 如果队列变空
        rear = 0;          // 重置rear指针
    return true;
}

#endif
