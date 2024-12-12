// twod.cpp -- 创建一个二维数组
#include <iostream>
#include "14.17_arraytp.h"
int main(void)
{
    using std::cout;
    using std::endl;
    ArrayTP<int, 10> sums;        // 存储每行元素之和
    ArrayTP<double, 10> aves;     // 存储每行平均值
    ArrayTP< ArrayTP<int,5>, 10> twodee;  // 二维数组
    
    int i, j;
    
    for (i = 0; i < 10; i++)
    {
        sums[i] = 0;
        for (j = 0; j < 5; j++)
        {
            twodee[i][j] = (i + 1) * (j + 1);  // 计算每个元素的值
            sums[i] += twodee[i][j];           // 累加每行的和
        }
        aves[i] = (double) sums[i] / 5;        // 计算每行的平均值
    }
    
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 5; j++)
        {
            cout.width(2);                      // 设置输出宽度为2
            cout << twodee[i][j] << ' ';       // 输出每个元素
        }
        cout << ": 和 = ";
        cout.width(3);                         // 设置输出宽度为3
        cout << sums[i] << ", 平均值 = " << aves[i] << endl;
    }
    
    cout << "完成.\n";
    return 0;
}
