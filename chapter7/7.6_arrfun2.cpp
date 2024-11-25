// arrfun2.cpp -- 带数组参数的函数示例
#include <iostream>
const int ArSize = 8;               // 定义数组大小常量
int sum_arr(int arr[], int n);      // 函数原型声明
// 使用std::而不是using指令
int main()
{
    int cookies[ArSize] = {1,2,4,8,16,32,64,128};
    // 注意：某些系统要求在int前加static关键字
    // 才能启用数组初始化
    std::cout << "cookies数组地址: "<< cookies << std::endl;
    // 某些系统可能需要类型转换：unsigned (cookies)

    std::cout << sizeof cookies << " = cookies的大小\n";
    int sum = sum_arr(cookies, ArSize);
    std::cout << "吃掉的饼干总数: " << sum << std::endl;
    sum = sum_arr(cookies, 3);      // 这是一个谎言（只计算前3个）
    std::cout << "前三个人吃掉了 " << sum << " 块饼干。\n";
    sum = sum_arr(cookies + 4, 4);  // 另一个谎言（只计算后4个）
    std::cout << "后四个人吃掉了 " << sum << " 块饼干。\n";
    return 0;
}

// 返回整型数组元素的和
int sum_arr(int arr[], int n)
{
    int total = 0;                  // 初始化总和为0
    std::cout << arr << " = arr数组地址, ";
    // 某些系统可能需要类型转换：unsigned (arr)
    
    std::cout << sizeof arr << " = arr的大小\n";
    // 遍历数组并累加元素
    for (int i = 0; i < n; i++)
        total = total + arr[i];
    return total;                   // 返回总和
}
