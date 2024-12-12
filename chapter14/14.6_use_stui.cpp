// use_stui.cpp -- 使用复合类
#include <iostream>
#include "14.4_studenti.h"
#include "14.5_student.cpp"
using std::cin;
using std::cout;
using std::endl;

// 函数声明:设置学生信息
void set(Student & sa, int n);
const int pupils = 3;  // 学生人数
const int quizzes = 5; // 测验次数

int main()
{
    // 创建3个Student对象的数组,每个对象可以存储5次测验成绩
    Student ada[pupils] = 
        {Student(quizzes), Student(quizzes), Student(quizzes)};

    int i;
    // 循环设置每个学生的信息
    for (i = 0; i < pupils; ++i)
        set(ada[i], quizzes);
    
    // 显示所有学生的名字
    cout << "\n学生列表:\n";
    for (i = 0; i < pupils; ++i)
        cout << ada[i].Name() << endl;
    
    // 显示每个学生的详细信息和平均分
    cout << "\n结果:";
    for (i = 0; i < pupils; ++i)
    {
        cout << endl << ada[i];
        cout << "平均分: " << ada[i].Average() << endl;
    }
    cout << "完成。\n";
    return 0;
}

// 设置学生信息的函数实现
void set(Student & sa, int n)
{
    cout << "请输入学生姓名: ";
    getline(cin, sa);  // 读取学生姓名
    cout << "请输入 " << n << " 个测验分数:\n";
    // 读取n个测验分数
    for (int i = 0; i < n; i++)
        cin >> sa[i];
    // 清除输入缓冲区
    while (cin.get() != '\n')
        continue;
}
