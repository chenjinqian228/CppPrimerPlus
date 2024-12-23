// cppPrimerPlus 17.17 -- 统计多个文件中的字符数
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
    using namespace std;
    if (argc == 1)    // 如果没有参数就退出
    {
        cerr << "用法: " << argv[0] << " 文件名[s]\n";
        exit(EXIT_FAILURE);
    }

    ifstream fin;     // 打开流
    long count;
    long total = 0;
    char ch;

    for (int file = 1; file < argc; file++)
    {
        fin.open(argv[file]);    // 将流连接到argv[file]
        if (!fin.is_open())
        {
            cerr << "无法打开 " << argv[file] << endl;
            fin.clear();
            continue;
        }
        count = 0;
        while (fin.get(ch))
            count++;
        cout << argv[file] << " 中有 " << count << " 个字符" << endl;
        total += count;
        fin.clear();        // 清除EOF标志
        fin.close();        // 断开文件连接
    }
    cout << "所有文件共有 " << total << " 个字符\n";
    return 0;
}
