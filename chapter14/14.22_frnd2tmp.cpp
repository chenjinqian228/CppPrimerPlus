// frnd2tmp.cpp -- 带有非模板友元的模板类
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class HasFriend
{
private:
    T item;
    static int ct;
public:
    HasFriend(const T & i) : item(i) { ct++; }
    ~HasFriend() { ct--; }
    friend void counts();
    friend void reports(HasFriend<T> &); // 模板参数
};

// 每个特化都有自己的静态数据成员
template <typename T>
int HasFriend<T>::ct = 0;

// 所有HasFriend<T>类的非模板友元
void counts()
{
    cout << "int计数: " << HasFriend<int>::ct << "; ";
    cout << "double计数: " << HasFriend<double>::ct << endl;
}

// HasFriend<int>类的非模板友元
void reports(HasFriend<int> & hf)
{
    cout << "HasFriend<int>: " << hf.item << endl;
}

// HasFriend<double>类的非模板友元
void reports(HasFriend<double> & hf)
{
    cout << "HasFriend<double>: " << hf.item << endl;
}

int main()
{
    cout << "未声明对象: ";
    counts();
    HasFriend<int> hfi1(10);
    cout << "声明hfi1后: ";
    counts();
    HasFriend<int> hfi2(20);
    cout << "声明hfi2后: ";
    counts();
    HasFriend<double> hfdb(10.5);
    cout << "声明hfdb后: ";
    counts();
    reports(hfi1);
    reports(hfi2);
    reports(hfdb);
    return 0;
}
