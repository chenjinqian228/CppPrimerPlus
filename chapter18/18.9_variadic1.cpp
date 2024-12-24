//variadici.cpp -- 使用递归方式解包参数包
#include <iostream>
#include <string>

// 0个参数的定义 -- 作为终止调用
void show_list3() {}

// 1个或多个参数的定义
template<typename T, typename... Args>
void show_list3( T value, Args... args)
{
    std::cout << value << ", ";
    show_list3(args...);
}

template <typename T>
void show_list3(T value){
    std::cout << value << std::endl;
}

int main()
{
    int n = 14;
    double x = 2.71828;
    std::string mr = "Mr. String objects!";
    
    show_list3(n, x);                  // 展示两个参数的调用
    show_list3(x*x, '!', 7, mr);       // 展示四个不同类型参数的调用
    return 0;
}
