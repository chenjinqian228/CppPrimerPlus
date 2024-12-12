// worker0.cpp -- 工作类方法
#include <iostream>
#include "14.7_worker0.h"
using namespace std;

// Worker方法

// 必须实现虚析构函数,即使是纯虚函数
Worker::~Worker() {}

// 设置Worker基类的姓名和ID
void Worker::Set()
{
    cout << "请输入工人姓名: ";
    getline(cin, fullname);
    cout << "请输入工人ID: ";
    cin >> id;
    while (cin.get() != '\n')  // 清除输入缓冲区
        continue;
}

// 显示Worker基类的信息
void Worker::Show() const
{
    cout << "姓名: " << fullname << "\n";
    cout << "员工ID: " << id << "\n";
}

// Waiter方法
// 设置服务员的信息,包括基类信息和优雅评分
void Waiter::Set()
{
    Worker::Set();  // 先设置基类信息
    cout << "请输入服务员的优雅评分: ";
    cin >> panache;
    while (cin.get() != '\n')  // 清除输入缓冲区
        continue;
}

// 显示服务员的所有信息
void Waiter::Show() const
{
    cout << "类别: 服务员\n";
    Worker::Show();  // 显示基类信息
    cout << "优雅评分: " << panache << "\n";
}

// Singer方法
// 定义声域范围的字符串数组
const char * Singer::pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};
// 设置歌手的信息,包括基类信息和声域范围
void Singer::Set()
{
    Worker::Set();  // 先设置基类信息
    cout << "请输入歌手声域范围对应的数字:\n";
    int i;
    // 显示所有声域选项
    for (i = 0; i < Vtypes; i++)
    {
        cout << i << ": " << pv[i] << "   ";
        if ( i % 4 == 3)
            cout << endl;
    }
    if (i % 4 != 0)
        cout << endl;
    // 输入并验证声域选择
    while (cin >> voice && (voice < 0 || voice >= Vtypes))
        cout << "请输入一个大于等于0且小于" << Vtypes << "的值" << endl;
    while (cin.get() != '\n')  // 清除输入缓冲区
        continue;
}

// 显示歌手的所有信息
void Singer::Show() const
{
    cout << "类别: 歌手\n";
    Worker::Show();  // 显示基类信息
    cout << "声域范围: " << pv[voice] << endl;
}
