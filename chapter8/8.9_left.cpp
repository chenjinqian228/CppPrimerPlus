// left.cpp -- 带默认参数的字符串函数
#include <iostream>
const int ArSize = 80;
char * left(const char * str, int n = 1);  // 函数原型，n的默认值为1

int main()
{
    using namespace std;
    char sample[ArSize];
    cout << "请输入一个字符串：\n";
    cin.get(sample,ArSize);  // 获取用户输入的字符串
    
    char *ps = left(sample, 4);  // 获取前4个字符
    cout << ps << endl;
    delete [] ps;       // 释放旧字符串的内存
    
    ps = left(sample);  // 使用默认参数，获取第一个字符
    cout << ps << endl;
    delete [] ps;       // 释放新字符串的内存
    return 0;
}

// 此函数返回一个指向新字符串的指针
// 新字符串由原字符串str的前n个字符组成
char * left(const char * str, int n)
{
    if(n < 0)          // 如果n为负数
        n = 0;         // 将n设为0
    
    char * p = new char[n+1];    // 动态分配内存，多分配一个字符用于存储结束符
    int i;
    
    // 复制字符，直到达到n个字符或遇到原字符串结束
    for (i = 0; i < n && str[i]; i++)
        p[i] = str[i];  // 复制字符
        
    // 将剩余位置都填充为结束符'\0'
    while (i <= n)
        p[i++] = '\0';
        
    return p;  // 返回新字符串的指针
}
