#include <iostream>
#include <fstream>    // 文件输入输出
#include <cstdlib>    // 为了使用exit()函数
const int SIZE = 60;  // 文件名最大长度

int main()
{
    using namespace std;

    char filename[SIZE];
    ifstream inFile;      // 创建文件输入处理对象
    cout << "请输入数据文件名：";
    cin.getline(filename, SIZE);
    inFile.open(filename);  // 将inFile与文件关联
    
    // 检查文件是否成功打开
    if (!inFile.is_open())
    {
        cout << "无法打开文件 " << filename << endl;
        cout << "程序终止。\n";
        exit(EXIT_FAILURE);
    }

    double value;         // 用于存储读取的值
    double sum = 0.0;     // 总和
    int count = 0;        // 记录读取的数据数量
    
    inFile >> value;      // 获取第一个值
    
    // 当输入正常且未到达文件末尾时继续循环
    while (inFile.good())
    {
        ++count;          // 计数加1
        sum += value;     // 累加值
        inFile >> value;  // 获取下一个值
    }

    // 判断文件读取结束的原因
    if (inFile.eof())
        cout << "已到达文件末尾。\n";
    else if (inFile.fail())
        cout << "输入因数据不匹配而终止。\n";
    else
        cout << "输入因未知原因终止。\n";

    // 输出处理结果
    if (count == 0)
        cout << "未处理任何数据。\n";
    else
    {
        cout << "读取的条目数：" << count << endl;
        cout << "总和：" << sum << endl;
        cout << "平均值：" << sum / count << endl;
    }
    
    inFile.close();    // 关闭文件
    return 0;
}
