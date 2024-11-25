//arrfun3.cpp -- 数组函数和const关键字的使用
#include <iostream>

const int Max = 5;
//函数原型
int fill_array(double ar[], int limit);     // 填充数组
void show_array(const double ar[], int n);  // 显示数组(不改变数据)
void revalue(double r, double ar[], int n); // 重新评估数组值

int main()
{
    using namespace std;
    double properties[Max];                 // 属性数组
    int size = fill_array(properties, Max); // 获取实际填充的数组大小
    show_array(properties, size);           // 显示数组内容
    if (size > 0)
    {
        cout << "请输入重新评估的系数: ";
        double factor;
        while (!(cin >> factor))           // 输入错误时
        {
            cin.clear();                   // 清除输入错误状态
            while (cin.get() != '\n')      // 清空输入缓冲区
                continue;
            cout << "输入错误；请输入一个数字: ";
        }
        revalue(factor, properties, size); // 重新计算数组值
        show_array(properties, size);      // 显示更新后的数组
    }
    cout << "程序结束.\n";
    cin.get();
    return 0;
}

int fill_array(double ar[], int limit)
{
    using namespace std;
    double temp;
    int i;
    for (i = 0; i < limit; i++)
    {
        cout << "请输入第" << (i + 1) << "个值: ";
        cin >> temp;
        if (!cin)                          // 输入错误时
        {
            cin.clear();                   // 清除输入错误状态
            while (cin.get() != '\n')      // 清空输入缓冲区
                continue;
            cout << "输入错误；输入过程终止.\n";
            break;
        }
        else if (temp < 0)                 // 输入负数时终止
            break;
        ar[i] = temp;
    }
    return i;                              // 返回实际填充的元素个数
}

// 以下函数可以使用数组ar，但不能修改它
// ar是数组的地址
void show_array(const double ar[], int n)
{
    using namespace std;
    for (int i = 0; i < n; i++)
    {
        cout << "属性 #" << (i + 1) << ": $";
        cout << ar[i] << endl;
    }
}

// 将ar[]数组的每个元素都乘以r
void revalue(double r, double ar[], int n)
{
    for (int i = 0; i < n; i++)
        ar[i] *= r;
}
