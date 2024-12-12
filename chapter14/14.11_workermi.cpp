// workermi.cpp -- 带有多重继承的工作类方法
#include "14.10_workermi.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Worker 类方法
// Worker 类的析构函数
Worker::~Worker() { }

// Worker 类的受保护方法
// 显示工人的基本信息(姓名和员工编号)
void Worker::Data() const {
    cout << "姓名: " << fullname << endl;
    cout << "员工编号: " << id << endl;
}

// 获取工人的基本信息
void Worker::Get() {
    getline(cin, fullname);
    cout << "请输入员工编号: ";
    cin >> id;
    while (cin.get() != '\n')
        continue;
}

// Waiter 类方法
// 设置服务员的所有信息
void Waiter::Set() {
    cout << "请输入服务员姓名: ";
    Worker::Get();  // 获取基本信息
    Get();          // 获取服务员特有信息
}

// 显示服务员的所有信息
void Waiter::Show() const {
    cout << "类别: 服务员\n";
    Worker::Data(); // 显示基本信息
    Data();         // 显示服务员特有信息
}

// Waiter 类的受保护方法
// 显示服务员的潇洒度评分
void Waiter::Data() const {
    cout << "潇洒度评分: " << panache << endl;
}

// 获取服务员的潇洒度评分
void Waiter::Get() {
    cout << "请输入服务员潇洒度评分: ";
    cin >> panache;
    while (cin.get() != '\n')
        continue;
}

// Singer 类方法
// 定义歌手声域类型的字符串数组
const char * Singer::pv[Singer::Vtypes] = {"other", "alto", "contralto",
    "soprano", "bass", "baritone", "tenor"};

// 设置歌手的所有信息
void Singer::Set() {
    cout << "请输入歌手姓名: ";
    Worker::Get();  // 获取基本信息
    Get();          // 获取歌手特有信息
}

// 显示歌手的所有信息
void Singer::Show() const {
    cout << "类别: 歌手\n";
    Worker::Data(); // 显示基本信息
    Data();         // 显示歌手特有信息
}

// Singer 类的受保护方法
// 显示歌手的声域类型
void Singer::Data() const {
    cout << "声域: " << pv[voice] << endl;
}

// 获取歌手的声域类型
void Singer::Get() {
    cout << "请输入歌手声域对应的数字:\n";
    int i;
    for (i = 0; i < Vtypes; i++) {
        cout << i << ": " << pv[i] << "   ";
        if (i % 4 == 3)
            cout << endl;
    }
    if (i % 4 != 0)
        cout << '\n';
    cin >> voice;
    while (cin.get() != '\n')
        continue;
}

// SingingWaiter 类方法(多重继承自 Singer 和 Waiter)
// 显示歌唱服务员的特有信息
void SingingWaiter::Data() const {
    Singer::Data(); // 显示歌手信息
    Waiter::Data(); // 显示服务员信息
}

// 获取歌唱服务员的特有信息
void SingingWaiter::Get() {
    Waiter::Get();  // 获取服务员信息
    Singer::Get();  // 获取歌手信息
}

// 设置歌唱服务员的所有信息
void SingingWaiter::Set() {
    cout << "请输入歌唱服务员姓名: ";
    Worker::Get();  // 获取基本信息
    Get();          // 获取特有信息
}

// 显示歌唱服务员的所有信息
void SingingWaiter::Show() const {
    cout << "类别: 歌唱服务员\n";
    Worker::Data(); // 显示基本信息
    Data();         // 显示特有信息
}
