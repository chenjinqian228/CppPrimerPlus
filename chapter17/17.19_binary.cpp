// binary.cpp -- 二进制文件 I/O
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>  // 用于 exit()

inline void eatline() { while (std::cin.get() != '\n') continue; }
struct planet
{
    char name[20];      // 行星名称
    double population;  // 行星人口
    double g;          // 重力加速度
};

const char * file = "planets.dat";

int main()
{
    using namespace std;
    planet pl;
    cout << fixed << right;

    // 显示初始内容
    ifstream fin;
    fin.open(file, ios_base::in | ios_base::binary);    // 二进制文件
    //注意: 某些系统不接受 ios_base::binary 模式
    if (fin.is_open())
    {
        cout << "以下是 " << file << " 文件的当前内容:\n";
        while (fin.read((char *) &pl, sizeof pl))
        {
            cout << setw(20) << pl.name << ": "
                << setprecision(0) << setw(12) << pl.population
                << setprecision(2) << setw(6) << pl.g << endl;
        }
        fin.close();
    }

    // 添加新数据
    ofstream fout(file, 
        ios_base::out | ios_base::app | ios_base::binary);
    //注意: 某些系统不接受 ios::binary 模式
    if (!fout.is_open())
    {
        cerr << "无法打开 " << file << " 文件进行输出:\n";
        exit(EXIT_FAILURE);
    }

    cout << "输入行星名称 (输入空行退出):\n";
    cin.get(pl.name, 20);
    while (pl.name[0] != '\0')
    {
        eatline();
        cout << "输入行星人口: ";
        cin >> pl.population;
        cout << "输入行星重力加速度: ";
        cin >> pl.g;
        eatline();
        fout.write((char *) &pl, sizeof pl);
        cout << "输入行星名称 (输入空行退出):\n";
        cin.get(pl.name, 20);
    }
    fout.close();

    // 显示更新后的文件
    fin.clear();    // 某些实现不需要,但不会有害
    fin.open(file, ios_base::in | ios_base::binary);
    if (fin.is_open())
    {
        cout << "以下是 " << file << " 文件的新内容:\n";
        while (fin.read((char *) &pl, sizeof pl))
        {
            cout << setw(20) << pl.name << ": "
                << setprecision(0) << setw(12) << pl.population
                << setprecision(2) << setw(6) << pl.g << endl;
        }
        fin.close();
    }
    cout << "完成.\n";
    return 0;
}
