// delete.cpp -- 演示delete运算符的使用
#include <iostream>
#include <cstring>      // 或使用 string.h
using namespace std;
char * getname(void);   // 函数原型

int main()
{
    char * name;        // 创建指针，但不分配存储空间
    
    name = getname();   // 将字符串的地址赋给name
    cout << name << " 位于 " << (int *) name << "\n";
    delete [] name;     // 释放内存
    
    name = getname();   // 重新使用已释放的内存
    cout << name << " 位于 " << (int *) name << "\n";
    delete [] name;     // 再次释放内存
    return 0;
}

char * getname()        // 返回指向新字符串的指针
{
    char temp[80];      // 临时存储空间
    cout << "请输入姓氏：";
    cin >> temp;
    char * pn = new char[strlen(temp) + 1];
    strcpy(pn, temp);   // 将字符串复制到更小的空间中
    
    return pn;         // 函数结束时temp将消失
}
