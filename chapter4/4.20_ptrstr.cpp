// strptr.cpp -- 使用字符串指针
#include <iostream>
#include <cstring>      // 声明 strlen()和strcpy()函数
int main()
{
    using namespace std;
    char animal[20] = "bear";  // animal 存储 "bear"（熊）
    const char * bird = "wren"; // bird 存储字符串的地址
    char * ps;                  // 未初始化的指针

    cout << animal << " and " ;
    cout << bird << endl;  // 显示 bear

    // cout << ps << "\n";      // 可能显示垃圾值，可能导致程序崩溃
    
    cout << "请输入一种动物: ";
    cin >> animal;              // 如果输入少于20个字符则没问题
    // cin >> ps;               // 这是一个可怕的错误，不要尝试；因为ps没有
                               // 指向已分配的空间

    ps = animal;               // 让ps指向字符串
    cout << ps << "\n";       // 没问题，等同于使用animal
    cout << "在使用strcpy()之前:\n";
    cout << animal << " 在地址 " << (int *) animal << endl;
    cout << ps << " 在地址 " << (int *) ps << endl;

    
    ps = new char[strlen(animal) + 1];  // 获取新的存储空间
    strcpy(ps, animal);        // 将字符串复制到新的存储空间
    cout << "使用strcpy()之后:\n";
    cout << animal << " 在地址 " << (int *) animal << endl;
    cout << ps << " 在地址 " << (int *) ps << endl;
    delete [] ps;              // 释放动态分配的内存
    return 0;
}
