// ruler.cpp -- 使用递归来细分标尺
#include <iostream>
const int Len = 88;     // 标尺的总长度
const int Divs = 8;     // 递归分割的层数
void subdivide(char ar[], int low, int high, int level);

int main()
{
    char ruler[Len];    // 创建用于存储标尺的字符数组
    int i;
    
    // 初始化标尺，填充空格
    for (i = 1; i < Len - 2; i++)
        ruler[i] = ' ';
    ruler[Len - 1] = '\0';    // 字符串结束符
    
    int max = Len - 2;        // 标尺右端位置
    int min = 0;              // 标尺左端位置
    ruler[min] = ruler[max] = '|';    // 在两端放置竖线标记
    
    // 打印初始标尺
    std::cout << ruler << std::endl;
    
    // 逐层处理分割
    for (i = 1; i <= Divs; i++)
    {
        subdivide(ruler,min,max,i);    // 递归分割标尺
        std::cout << ruler << std::endl;    // 打印每一层的结果
    }

    return 0;
}

// 递归函数：分割标尺
// ar[]: 标尺数组
// low: 当前处理段的左端点
// high: 当前处理段的右端点
// level: 当前递归层级
void subdivide(char ar[], int low, int high, int level)
{
    if (level == 0)    // 递归基线条件：当层级为0时返回
        return;
    int mid = (high + low) / 2;    // 计算中点
    ar[mid] = '|';    // 在中点位置放置标记
    
    // 递归处理左半部分
    subdivide(ar, low, mid, level - 1);
    // 递归处理右半部分
    subdivide(ar, mid, high, level - 1);
}
