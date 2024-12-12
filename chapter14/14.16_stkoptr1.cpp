// stkoptr1.cpp -- 测试指针栈
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "14.15_stcktp1.h"

const int Num = 10;

int main()
{
    std::srand(std::time(0));     // 随机化rand()函数
    std::cout << "请输入栈的大小: ";
    int stacksize;
    std::cin >> stacksize;
    
    // 创建一个具有stacksize个槽位的空栈
    Stack<const char *> st(stacksize); 
    
    // 输入篮子
    const char * in[Num] = {
        " 1: 汉克·吉尔伽美什", " 2: 琪琪·伊什塔尔",
        " 3: 贝蒂·罗克", " 4: 伊恩·弗拉格兰蒂",
        " 5: 沃尔夫冈·基布尔", " 6: 波西亚·库普",
        " 7: 乔伊·阿尔蒙多", " 8: 泽维尔·帕普里卡",
        " 9: 胡安·摩尔", "10: 米莎·马切"
    };
    
    // 输出篮子
    const char * out[Num];
    
    int processed = 0;
    int nextin = 0;
    
    while (processed < Num)
    {
        if (st.isempty())
            st.push(in[nextin++]);
        else if (st.isfull())
            st.pop(out[processed++]);
        else if (std::rand() % 2 && nextin < Num)   // 50-50的概率
            st.push(in[nextin++]);
        else
            st.pop(out[processed++]);
    }
    
    for (int i = 0; i < Num; i++)
        std::cout << out[i] << std::endl;
        
    std::cout << "再见\n";
    return 0;
}
