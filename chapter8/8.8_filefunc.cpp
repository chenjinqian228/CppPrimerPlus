// filefunc.cpp -- 带有 ostream & 参数的函数
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void file_it(ostream & os, double fo, const double fe[], int n);
const int LIMIT = 5;

int main()
{
    ofstream fout;
    const char * fn = "ep-data.txt";
    fout.open(fn);
    if (!fout.is_open())
    {
        cout << "无法打开文件 " << fn << "。程序退出。\n";
        exit(EXIT_FAILURE);
    }
    double objective;
    cout << "请输入您的望远镜物镜焦距（单位：毫米）：";
    cin >> objective;
    double eps[LIMIT];
    cout << "请输入 " << LIMIT << " 个目镜的焦距（单位：毫米）：\n";
    for (int i = 0; i < LIMIT; i++)
    {
        cout << "目镜 #" << i + 1 << ": ";
        cin >> eps[i];
    }
    file_it(fout, objective, eps, LIMIT);   // 写入文件
    file_it(cout, objective, eps, LIMIT);    // 显示在屏幕上
    cout << "完成\n";
    return 0;
}

void file_it(ostream & os, double fo, const double fe[], int n)
{
    ios_base::fmtflags initial;
    initial = os.setf(ios_base::fixed);    // 保存初始格式化状态
    os.precision(0);
    os << "物镜焦距: " << fo << " 毫米\n";
    os.setf(ios::showpoint);
    os.precision(1);
    os.width(12);
    os << "目镜焦距";
    os.width(15);
    os << "放大倍数" << endl;
    for (int i = 0; i < n; i++)
    {
        os.width(12);
        os << fe[i];
        os.width(15);
        os << int (fo/fe[i] + 0.5) << endl;  // 计算放大倍数并四舍五入
    }
    os.setf(initial);    // 恢复初始格式化状态
}
