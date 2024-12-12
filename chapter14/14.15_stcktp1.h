// stcktp1.h -- 改进的栈模板
#ifndef STCKTP1_H_
#define STCKTP1_H_

template <class Type>
class Stack
{
private:
    enum {SIZE = 10};    // 默认大小
    int stacksize;       // 栈的大小
    Type * items;        // 存放栈项的数组
    int top;            // 栈顶项的索引
public:
    explicit Stack(int ss = SIZE);    // 构造函数
    Stack(const Stack & st);          // 拷贝构造函数
    ~Stack() { delete [] items; }     // 析构函数
    bool isempty() { return top == 0; }      // 检查栈是否为空
    bool isfull() { return top == stacksize; }// 检查栈是否已满
    bool push(const Type & item);     // 将项添加到栈中
    bool pop(Type & item);            // 弹出栈顶项到item中
    Stack & operator=(const Stack & st);// 赋值运算符重载
};

// 构造函数
template <class Type>
Stack<Type>::Stack(int ss) : stacksize(ss), top(0)
{
    items = new Type[stacksize];
}

// 拷贝构造函数
template <class Type>
Stack<Type>::Stack(const Stack & st)
{
    stacksize = st.stacksize;    // 复制栈大小
    top = st.top;               // 复制栈顶索引
    items = new Type[stacksize]; // 创建新数组
    // 复制所有元素
    for (int i = 0; i < top; i++)
        items[i] = st.items[i];
}

// 压栈操作
template <class Type>
bool Stack<Type>::push(const Type & item)
{
    if (top < stacksize)
    {
        items[top++] = item;    // 添加项并增加栈顶索引
        return true;            // 压栈成功
    }
    else
        return false;           // 栈已满，压栈失败
}

// 出栈操作
template <class Type>
bool Stack<Type>::pop(Type & item)
{
    if (top > 0)
    {
        item = items[--top];    // 将栈顶项赋给item并减少栈顶索引
        return true;            // 出栈成功
    }
    else
        return false;           // 栈为空，出栈失败
}

// 赋值运算符重载
template <class Type>
Stack<Type> & Stack<Type>::operator=(const Stack<Type> & st)
{
    if (this == &st)           // 自赋值检查
        return *this;
    delete [] items;           // 删除原有数组
    stacksize = st.stacksize;  // 复制栈大小
    top = st.top;             // 复制栈顶索引
    items = new Type[stacksize]; // 创建新数组
    // 复制所有元素
    for (int i = 0; i < top; i++)
        items[i] = st.items[i];
    return *this;             // 返回调用对象的引用
}

#endif
