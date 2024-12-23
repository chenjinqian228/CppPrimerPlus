// append.cpp -- 向文件追加信息
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>          // 用于 exit() 函数

const char * file = "guests.txt";
int main()
{
    using namespace std;
    char ch;

    // 显示初始内容
    ifstream fin;
    fin.open(file);

    if (fin.is_open())
    {
        cout << "以下是 " << file << " 文件的当前内容:\n";
        while (fin.get(ch))
            cout << ch;
        fin.close();
    }

    // 添加新名字
    ofstream fout(file, ios::out | ios::app);    // 追加模式
    if (!fout.is_open())
    {
        cerr << "无法打开 " << file << " 文件进行输出。\n";
        exit(EXIT_FAILURE);
    }

    cout << "请输入客人姓名 (输入空行退出):\n";
    string name;
    while (getline(cin,name) && name.length() > 0)
    {
        fout << name << endl;
    }
    fout.close();

    // 显示修改后的文件
    fin.clear();    // 某些编译器可能不需要
    fin.open(file);
    if (fin.is_open())
    {
        cout << "以下是 " << file << " 文件的新内容:\n";
        while (fin.get(ch))
            cout << ch;
        fin.close();
    }
    cout << "完成。\n";
    return 0;
}
