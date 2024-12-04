// stack.cpp -- 栈类成员函数的实现
#include "10.10_stack.h"

Stack::Stack()    // 创建一个空栈
{
    top = 0;     // 将栈顶索引初始化为0
}

bool Stack::isempty() const    // 判断栈是否为空
{
    return top == 0;          // 如果top为0则栈为空
}

bool Stack::isfull() const     // 判断栈是否已满
{
    return top == MAX;        // 如果top等于MAX则栈已满
}

bool Stack::push(const Item & item)    // 将元素压入栈中
{
    if (top < MAX)                     // 如果栈未满
    {
        items[top++] = item;           // 将新元素存入栈顶并增加top
        return true;                   // 压栈成功返回true
    }
    else
        return false;                  // 栈已满，压栈失败返回false
}

bool Stack::pop(Item & item)           // 将栈顶元素弹出
{
    if (top > 0)                       // 如果栈非空
    {
        item = items[--top];           // 先将top减1，然后返回栈顶元素
        return true;                   // 弹栈成功返回true
    }
    else
        return false;                  // 栈为空，弹栈失败返回false
}
