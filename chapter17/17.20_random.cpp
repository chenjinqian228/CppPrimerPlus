// random.cpp -- 二进制文件的随机访问
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

const int LIM = 20;

struct planet {
    char name[LIM];     // 行星名称
    double population;   // 行星人口
    double g;           // 重力加速度
};

const char* file = "planets.dat";

inline void eatline() { while (std::cin.get() != '\n') continue; }

int main() {
    using namespace std;
    planet pl;
    cout << fixed;

    // 显示初始内容
    fstream finout;
    finout.open(file, ios_base::in | ios_base::out | ios_base::binary);
    if (finout.is_open()) {
        cout << "以下是 " << file << " 文件的当前内容：\n";
        while (finout.read((char*)&pl, sizeof pl)) {
            cout << setw(20) << pl.name << ": "
                << setprecision(0) << setw(12) << pl.population
                << setprecision(2) << setw(6) << pl.g << endl;
        }
        if (finout.eof())
            finout.clear();
        else {
            cerr << "读取 " << file << " 时发生错误。\n";
            exit(EXIT_FAILURE);
        }
    }
    else {
        cerr << file << " 无法打开 -- 再见。\n";
        exit(EXIT_FAILURE);
    }

    // 修改记录
    cout << "请输入要修改的记录编号：";
    long rec;
    cin >> rec;
    eatline();
    if (rec < 0 || rec >= 3) {
        cerr << "无效的记录编号 -- 再见\n";
        exit(EXIT_FAILURE);
    }
    streampos place = rec * sizeof pl;
    finout.seekg(place);
    if (finout.fail()) {
        cerr << "定位时发生错误\n";
        exit(EXIT_FAILURE);
    }

    finout.read((char*)&pl, sizeof pl);
    cout << "您选择的是：\n";
    cout << rec << ": " << setw(20) << pl.name << ": "
        << setprecision(0) << setw(12) << pl.population
        << setprecision(2) << setw(6) << pl.g << endl;
    if (finout.eof())
        finout.clear();

    cout << "请输入行星名称：";
    cin.get(pl.name, LIM);
    eatline();
    cout << "请输入行星人口：";
    cin >> pl.population;
    cout << "请输入行星重力加速度：";
    cin >> pl.g;
    finout.seekp(place);
    finout.write((char*)&pl, sizeof pl) << flush;
    if (finout.fail()) {
        cerr << "写入时发生错误\n";
        exit(EXIT_FAILURE);
    }

    // 显示修改后的文件
    finout.seekg(0);
    cout << "以下是 " << file << " 文件的新内容：\n";
    while (finout.read((char*)&pl, sizeof pl)) {
        cout << setw(20) << pl.name << ": "
            << setprecision(0) << setw(12) << pl.population
            << setprecision(2) << setw(6) << pl.g << endl;
    }
    finout.close();
    cout << "完成。\n";
    return 0;
}
