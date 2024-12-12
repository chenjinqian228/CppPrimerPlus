#ifndef STACKTP_H_
#define STACKTP_H_

// 这是一个模板栈类的实现
// 使用数组来存储栈元素,支持基本的栈操作:
// 压栈(push)、出栈(pop)、判空(isempty)、判满(isfull)
template <class Type>
class Stack {
private:
    enum {MAX = 10};    // 定义栈的最大容量为10
    Type items[MAX];    // 用数组存储栈元素
    int top;            // 栈顶指针,指向下一个可用位置
public:
    Stack();            // 构造函数,初始化栈
    bool isempty();     // 判断栈是否为空:top=0表示栈空
    bool isfull();      // 判断栈是否已满:top=MAX表示栈满
    bool push(const Type & item); // 入栈操作,成功返回true
    bool pop(Type & item);        // 出栈操作,成功返回true
};

// 构造函数:初始化栈顶指针为0
template <class Type>
Stack<Type>::Stack() {
    top = 0;  
}

// 判断栈是否为空
template <class Type>
bool Stack<Type>::isempty() {
    return top == 0;
}

// 判断栈是否已满
template <class Type>
bool Stack<Type>::isfull() {
    return top == MAX;
}

// 入栈操作
template <class Type>
bool Stack<Type>::push(const Type & item) {
    if (top < MAX) {       // 栈未满时
        items[top++] = item;  // 存入元素并递增top
        return true;
    }
    else
        return false;      // 栈满时返回false
}

// 出栈操作
template <class Type>
bool Stack<Type>::pop(Type & item) {
    if (top > 0) {        // 栈非空时
        item = items[--top];  // 先减少top,再取出元素
        return true;
    }
    else
        return false;      // 栈空时返回false
}

#endif
