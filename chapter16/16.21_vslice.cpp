// vslice.cpp -- 演示使用 valarray 切片功能
#include <iostream>
#include <valarray>
#include <cstdlib>

const int SIZE = 12;
typedef std::valarray<int> vint;    // 简化声明，为 valarray<int> 定义别名
void show(const vint & v, int cols);  // 显示函数声明

int main()
{
    using std::slice;               // 从 <valarray> 引入 slice
    using std::cout;
    vint valint(SIZE);             // 创建大小为12的数组，可以看作4行3列

    int i;
    for (i = 0; i < SIZE; ++i)
        valint[i] = std::rand() % 10;  // 用0-9的随机数填充数组
    cout << "原始数组：\n";
    show(valint, 3);               // 以3列的形式显示数组

    vint vcol(valint[slice(1,4,3)]); // 提取第2列（起始位置1，长度4，步长3）
    cout << "第二列：\n";
    show(vcol, 1);                 // 以1列的形式显示

    vint vrow(valint[slice(3,3,1)]); // 提取第2行（起始位置3，长度3，步长1）
    cout << "第二行：\n";
    show(vrow, 3);

    valint[slice(2,4,3)] = 10;     // 将第3列全部设置为10
    cout << "将最后一列设置为10：\n";
    show(valint, 3);

    cout << "将第一列设置为后两列之和：\n";
    // 由于切片不能直接相加，需要先转换为valarray<int>
    valint[slice(0,4,3)] = vint(valint[slice(1,4,3)])
                         + vint(valint[slice(2,4,3)]);
    show(valint, 3);
    return 0;
}

// 显示函数实现
void show(const vint & v, int cols)
{
    using std::cout;
    using std::endl;

    int lim = v.size();
    for (int i = 0; i < lim; ++i)
    {
        cout.width(3);             // 设置输出宽度为3
        cout << v[i];              // 输出数组元素
        if (i % cols == cols - 1)  // 如果是每行的最后一个元素
            cout << endl;          // 换行
        else
            cout << ' ';           // 否则输出空格
    }
    if (lim % cols != 0)          // 如果最后一行不完整
        cout << endl;             // 额外换行
}
