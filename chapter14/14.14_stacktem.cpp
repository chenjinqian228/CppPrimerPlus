// stacktem.cpp -- 测试模板栈类
#include <iostream>
#include <string>
#include <cctype>
#include "14.13_stacktp.h"
using namespace std;

int main()
{
    Stack<string> st;  // 创建一个空栈
    char ch;
    string po;
    cout << "请输入 A 添加采购订单，\n"
         << "输入 P 处理采购订单，或输入 Q 退出。\n";
    while (cin >> ch && toupper(ch) != 'Q')  // 循环直到用户输入Q退出
    {
        while (cin.get() != '\n')   // 清除输入缓冲区
            continue;
        if (!isalpha(ch))           // 检查输入是否为字母
        {
            cout << '\a';           // 如果不是字母则发出警告声
            continue;
        }
        switch(ch)
        {
            case 'A':              // 处理添加订单的情况
            case 'a': cout << "输入要添加的采购订单号: ";
                     cin >> po;
                     if (st.isfull())    // 检查栈是否已满
                         cout << "栈已满\n";
                     else
                         st.push(po);    // 将订单号压入栈
                     break;
            case 'P':              // 处理处理订单的情况  
            case 'p': if (st.isempty())  // 检查栈是否为空
                         cout << "栈已空\n";
                     else {
                         st.pop(po);      // 从栈中弹出订单号
                         cout << "采购订单号 #" << po << " 已弹出\n";
                     }
                     break;
        }
        cout << "请输入 A 添加采购订单，\n"
             << "输入 P 处理采购订单，或输入 Q 退出。\n";
    }
    cout << "再见\n";
    return 0;
}
