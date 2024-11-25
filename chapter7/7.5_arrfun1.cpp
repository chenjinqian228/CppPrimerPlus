// arrfun1.cpp -- 带数组参数的函数示例
#include <iostream>
const int ArSize = 8;               // 定义数组大小常量
int sum_arr(int arr[], int n);      // 函数原型声明

int main()
{
    using namespace std;
    // 初始化一个包含8个元素的整型数组
    int cookies[ArSize] = {1,2,4,8,16,32,64,128};
    // 注意：某些系统要求在 int 前面加上 static 关键字
    // 才能启用数组初始化
    
    // 调用函数计算数组元素之和
    int sum = sum_arr(cookies, ArSize);
    // 输出结果
    cout << "饼干总数：" << sum << "\n";
    return 0;
}

// 返回整型数组元素的和
int sum_arr(int arr[], int n)
{
    int total = 0;                  // 初始化总和为0
    // 遍历数组所有元素并累加
    for (int i = 0; i < n; i++)
        total = total + arr[i];
    return total;                   // 返回总和
}
