// arrfun4.cpp -- 使用数组范围的函数示例
#include <iostream>
const int ArSize = 8;
int sum_arr(const int * begin, const int * end); // 计算指定范围内数组元素和的函数

int main()
{
    using namespace std;
    
    // 初始化饼干数量数组
    int cookies[ArSize] = {1,2,4,8,16,32,64,128};
    // 注意：某些系统可能需要在int前添加static关键字
    // 才能启用数组初始化
    
    // 计算所有饼干的总数
    int sum = sum_arr(cookies, cookies + ArSize);
    cout << "吃掉的饼干总数: " << sum << endl;

    // 计算前三个人吃掉的饼干数
    sum = sum_arr(cookies, cookies + 3);    // 前3个元素
    cout << "前三个人总共吃掉 " << sum << " 块饼干。\n";

    // 计算最后四个人吃掉的饼干数
    sum = sum_arr(cookies + 4, cookies + 8); // 最后4个元素
    cout << "最后四个人总共吃掉 " << sum << " 块饼干。\n";
    return 0;
}

// 计算整数数组指定范围内元素的和
int sum_arr(const int * begin, const int * end)
{
    const int * pt;        // 用于遍历数组的指针
    int total = 0;         // 初始化总和为0
    
    // 从begin指针开始，直到达到end指针为止
    for (pt = begin; pt != end; pt++)
        total = total + *pt;  // 将当前指针指向的值加到总和中
    return total;
}
