//outfile.cpp -- 写入文件示例
#include <iostream>    // 输入输出流
#include <fstream>     // 文件流

int main()
{
    using namespace std;

    char automobile[50];   // 存储汽车品牌型号的字符数组
    int year;             // 存储年份
    double a_price;       // 原始价格(asking price)
    double d_price;       // 折扣价格(discounted price)
    
    ofstream outFile;     // 创建输出文件对象
    outFile.open("carinfo.txt"); // 将对象与文件关联
    
    // 获取用户输入信息
    cout << "请输入汽车品牌和型号：";
    cin.getline(automobile, 50);
    cout << "请输入生产年份：";
    cin >> year;
    cout << "请输入原始售价：";
    cin >> a_price;
    
    // 计算折扣价（原价的91.3%）
    d_price = 0.913 * a_price;

    // 在屏幕上显示信息（使用cout）
    cout << fixed;                    // 使用固定小数点表示
    cout.precision(2);                // 设置精确度为2位小数
    cout.setf(ios_base::showpoint);   // 显示小数点和尾随零
    cout << "品牌和型号：" << automobile << endl;
    cout << "年份：" << year << endl;
    cout << "原始售价：$" << a_price << endl;
    cout << "现售价：$" << d_price << endl;

    // 将相同的信息写入文件（使用outFile替代cout）
    outFile << fixed;
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile << "品牌和型号：" << automobile << endl;
    outFile << "年份：" << year << endl;
    outFile << "原始售价：$" << a_price << endl;
    outFile << "现售价：$" << d_price << endl;

    outFile.close();    // 关闭文件
    return 0;
}
