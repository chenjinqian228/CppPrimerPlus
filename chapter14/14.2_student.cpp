// studentc.cpp -- Student类使用包含
#include "14.1_studentc.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;

// 公有方法
// 计算平均分数 - 如果有分数则返回平均值,否则返回0
double Student::Average() const
{
    if (scores.size() > 0)
        return scores.sum()/scores.size();
    else
        return 0;
}

// 返回学生姓名
const string & Student::Name() const
{
    return name;
}

// 重载[]运算符,可修改分数
double & Student::operator[](int i)
{
    return scores[i]; // 使用valarray<double>::operator[]()
}

// 重载[]运算符,只读访问分数
double Student::operator[](int i) const
{
    return scores[i];
}

// 私有方法
// 输出分数数组,每行5个分数
ostream & Student::arr_out(ostream & os) const
{
    int i;
    int lim = scores.size();
    if (lim > 0)
    {
        for (i = 0; i < lim; i++)
        {
            os << scores[i] << " ";
            if (i % 5 == 4)
                os << endl;
        }
        if (i % 5 != 0)
            os << endl;
    }
    else
        os << " 空数组 ";
    return os;
}

// 友元函数
// 重载>>运算符,输入学生姓名
istream & operator>>(istream & is, Student & stu)
{
    is >> stu.name;
    return is;
}

// 使用getline读取一行作为学生姓名
istream & getline(istream & is, Student & stu)
{
    getline(is, stu.name);
    return is;
}

// 重载<<运算符,输出学生姓名和分数
ostream & operator<<(ostream & os, const Student & stu)
{
    os << "分数为 " << stu.name << ":\n";
    stu.arr_out(os);
    return os;
}
