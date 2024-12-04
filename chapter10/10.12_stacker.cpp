// stacker.cpp -- 测试Stack类
#include <iostream>
#include <cctype>
#include "10.10_stack.h"
#include "10.11_stack.cpp"
int main()
{
    using namespace std;
    Stack st;                  // 创建一个空栈
    char ch;
    unsigned long po;
    cout << "请输入 A 来添加采购订单，\n"
         << "输入 P 来处理采购订单，或输入 Q 退出。\n";
    while (cin >> ch && toupper(ch) != 'Q')    // 读取输入直到用户输入'Q'或'q'
    {
        while (cin.get() != '\n')              // 清除输入缓冲区中的剩余字符
            continue;
        if (!isalpha(ch))                      // 如果输入的不是字母
        {
            cout << '\a';                      // 发出警告音
            continue;
        }
        switch(ch)
        {
            case 'A':                          // 处理添加订单的情况
            case 'a': cout << "请输入要添加的采购订单号: ";
                     cin >> po;
                     if (st.isfull())
                         cout << "栈已经满了\n";
                     else
                         st.push(po);
                     break;
            case 'P':                          // 处理处理订单的情况
            case 'p': if (st.isempty())
                         cout << "栈已经空了\n";
                     else {
                         st.pop(po);
                         cout << "采购订单 #" << po << " 已处理\n";
                     }
                     break;
        }
        cout << "请输入 A 来添加采购订单，\n"
             << "输入 P 来处理采购订单，或输入 Q 退出。\n";
    }
    cout << "再见\n";
    return 0;
}
