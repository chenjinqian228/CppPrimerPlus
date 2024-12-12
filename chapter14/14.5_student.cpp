// studenti.cpp -- Student类使用私有继承
#include "14.4_studenti.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;

// 公有方法
// 计算学生分数的平均值
double Student::Average() const
{
    if (ArrayDb::size() > 0)
        return ArrayDb::sum()/ArrayDb::size(); // 总和除以数量得到平均值
    else
        return 0;
}

// 返回学生姓名
const string & Student::Name() const
{
    return (const string &) *this; // 将this指针转换为string引用并返回
}

// 重载[]运算符的非const版本,用于访问和修改分数
double & Student::operator[](int i)
{
    return ArrayDb::operator[](i); // 调用基类ArrayDb的[]运算符
}

// 重载[]运算符的const版本,仅用于访问分数
double Student::operator[](int i) const
{
    return ArrayDb::operator[](i);
}

// 私有方法
// 输出分数数组的辅助函数
ostream & Student::arr_out(ostream & os) const
{
    int i;
    int lim = ArrayDb::size();
    if (lim > 0)
    {
        for (i = 0; i < lim; i++)
        {
            os << ArrayDb::operator[](i) << " "; // 输出每个分数
            if (i % 5 == 4)                      // 每5个分数换行
                os << endl;
        }
        if (i % 5 != 0)                         // 如果最后一行不满5个,补充换行
            os << endl;
    }
    else
        os << " 空数组 ";
    return os;
}

// 友元函数
// 重载>>运算符用于输入学生姓名
istream & operator>>(istream & is, Student & stu)
{
    is >> (string &)stu;  // 将Student对象转换为string后输入
    return is;
}

// 使用getline读取包含空格的学生姓名
istream & getline(istream & is, Student & stu)
{
    getline(is, (string &)stu);  // 将Student对象转换为string后使用getline
    return is;
}

// 重载<<运算符用于输出学生信息
ostream & operator<<(ostream & os, const Student & stu)
{
    os << "分数为 " << (const string &)stu << ":\n"; // 输出姓名
    stu.arr_out(os);  // 使用私有方法输出分数数组
    return os;
}
