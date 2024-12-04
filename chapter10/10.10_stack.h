// stack.h -- 栈的抽象数据类型(ADT)类定义
#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;  // 定义Item类型为无符号长整型

class Stack  // 栈类
{
private:
    enum {MAX = 10};      // 类专用的常量，定义栈的最大容量
    Item items[MAX];      // 存储栈元素的数组
    int top;             // 栈顶元素的索引
public:
    Stack();             // 构造函数
    bool isempty() const;    // 检查栈是否为空
    bool isfull() const;     // 检查栈是否已满
    // push()函数：如果栈已满则返回false，否则返回true
    bool push(const Item & item);    // 将元素添加到栈中
    // pop()函数：如果栈已空则返回false，否则返回true
    bool pop(Item & item);           // 将栈顶元素弹出并存入item中
};
#endif
