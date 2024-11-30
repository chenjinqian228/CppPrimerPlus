// leftover.cpp -- left()函数的重载示例
#include <iostream>
// 函数原型
unsigned long left(unsigned long num, unsigned ct);
char * left(const char * str, int n = 1);

int main()
{
    using namespace std;
    const char* trip = "Hawaii!!";    // 正确的方式;    // 测试字符串
    unsigned long n = 12345678;  // 测试数字
    int i;
    char * temp;

    for (i = 1; i < 10; i++)
    {
        cout << left(n, i) << endl;      // 调用数字版本
        temp = left(trip,i);             // 调用字符串版本
        cout << temp << endl;
        delete [] temp;                   // 释放临时存储空间
    }
    return 0;
}

// 此函数返回数字num的前ct位
unsigned long left(unsigned long num, unsigned ct)
{
    unsigned digits = 1;         // 记录数字的位数
    unsigned long n = num;

    if (ct == 0 || num == 0)
        return 0;               // 如果没有位数，返回0
        
    // 计算数字的位数
    while (n /= 10)
        digits++;
        
    if (digits > ct)           // 如果总位数大于要求的位数
    {
        ct = digits - ct;      // 计算需要除以10的次数
        while (ct--)
            num /= 10;
        return num;            // 返回左边的数字
    }
    else                       // 如果ct大于等于数字的位数
        return num;            // 返回整个数字
}

// 此函数返回一个指向新字符串的指针
// 新字符串由原字符串str的前n个字符组成
char * left(const char * str, int n)
{
    if(n < 0)
        n = 0;
    char * p = new char[n+1];    // 创建新的字符数组
    int i;
    
    // 复制字符
    for (i = 0; i < n && str[i]; i++)
        p[i] = str[i];  // 复制字符
        
    // 添加字符串结束符
    while (i <= n)
        p[i++] = '\0';  
    return p; 
}
