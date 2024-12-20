// valvect.cpp -- 比较 vector 和 valarray 的使用
#include <iostream>     // 输入输出流
#include <valarray>     // valarray 数组
#include <vector>       // vector 容器
#include <algorithm>    // 算法库，用于排序
int main()
{
    using namespace std;
    vector<double> data;    // 创建一个存储双精度数的vector容器
    double temp;            // 临时变量，用于存储输入的数据

    cout << "请输入数字（输入小于等于0的数字结束）:\n";
    // 循环读取输入，直到输入小于等于0的数
    while (cin >> temp && temp > 0)
        data.push_back(temp);   // 将数据添加到vector末尾
    
    sort(data.begin(), data.end());    // 对vector中的数据进行排序
    int size = data.size();            // 获取数据个数
    
    // 创建一个与vector等大的valarray数组
    valarray<double> numbers(size);
    int i;
    // 将vector中的数据复制到valarray中
    for (i = 0; i < size; i++)
        numbers[i] = data[i];
    
    // 创建一个用于存储平方根的valarray
    valarray<double> sq_rts(size);
    sq_rts = sqrt(numbers);    // 计算每个数的平方根
    
    // 创建一个用于存储结果的valarray
    valarray<double> results(size);
    results = numbers + 2.0 * sq_rts;    // 计算：原数 + 2.0 * 平方根
    
    cout.setf(ios_base::fixed);     // 设置为固定小数点格式
    cout.precision(4);              // 设置精确度为4位小数
    
    // 输出结果
    for (i = 0; i < size; i++)
    {
        cout.width(8);              // 设置字段宽度为8
        cout << numbers[i] << ": ";  // 输出原始数据
        cout.width(8);              // 设置字段宽度为8
        cout << results[i] << endl;  // 输出计算结果
    }
    cout << "完成\n";
    return 0;
}
