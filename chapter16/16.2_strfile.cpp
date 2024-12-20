// strfile.cpp -- 从文件中读取字符串
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main()
{
    using namespace std;
    ifstream fin;                    // 创建输入文件流对象
    fin.open("tobuy.txt");          // 打开名为tobuy.txt的文件
    if (fin.is_open() == false)     // 如果文件打开失败
    {
        cerr << "无法打开文件。程序退出。\n";
        exit(EXIT_FAILURE);          // 异常退出程序
    }

    string item;                     // 存储读取的字符串
    int count = 0;                  // 计数器初始化为0
    getline(fin, item, ':');        // 读取文件内容，以冒号为分隔符
    while (fin)                     // 当输入正常时继续循环
    {
        ++count;                    // 计数器加1
        cout << count << ": " << item << endl;  // 输出计数和内容
        getline(fin, item,':');     // 继续读取下一段内容
    }

    cout << "完成！\n";             // 输出完成信息
    fin.close();                    // 关闭文件
    return 0;                       // 程序正常结束
}
