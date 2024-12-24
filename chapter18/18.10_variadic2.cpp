// variadic2.cpp -- 变参模板示例2
#include <iostream>
#include <string>

// 定义0个参数的情况
void show_list() {}

// 定义1个参数的情况
template<typename T>
void show_list(const T& value)
{
    std::cout << value << '\n';
}

// 定义2个或更多参数的情况
template<typename T, typename... Args>
void show_list(const T& value, const Args&... args)
{
    std::cout << value << ", ";
    show_list(args...);
}

int main()
{
    int n = 14;
    double x = 2.71828;
    std::string mr = "Mr. String objects!";
    
    show_list(n, x);                  // 展示两个参数的调用
    show_list(x*x, '!', 7, mr);       // 展示四个不同类型参数的调用
    return 0;
}
