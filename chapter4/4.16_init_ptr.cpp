// init_ptr.cpp -- 指针初始化示例
#include <iostream>
int main()
{
    using namespace std;
    int higgens = 5;        // 声明一个整型变量higgens并赋值为5
    int * pt = &higgens;    // 声明指针pt，并将其指向higgens的地址


    cout << "higgens的值 = " << higgens << endl;
    cout << "higgens的地址 = " << &higgens << endl;
    cout << "*pt的值 = " << *pt << endl;
    cout << "pt的值（存储的地址） = " << pt << endl;
    
    return 0;
}
