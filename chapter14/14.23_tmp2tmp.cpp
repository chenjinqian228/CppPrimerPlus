// tmp2tmp.cpp -- 模板友元类的模板类
#include <iostream>
using std::cout;
using std::endl;

// 模板原型
template <typename T> void counts();
template <typename T> void report(T &);

// 模板类
template <typename TT>
class HasFriendT
{
private:
    TT item;
    static int ct;
public:
    HasFriendT(const TT & i) : item(i) {ct++;}
    ~HasFriendT() { ct--; }
    friend void counts<TT>();
    friend void report<>(HasFriendT<TT> &);
};

template <typename T>
int HasFriendT<T>::ct = 0;

// 模板友元函数定义
template <typename T>
void counts()
{
    cout << "模板大小: " << sizeof(HasFriendT<T>) << "; ";
    cout << "模板 counts(): " << HasFriendT<T>::ct << endl;
}

template <typename T>
void report(T & hf)
{
    cout << hf.item << endl;
}

int main()
{
    counts<int>();
    HasFriendT<int> hfi1(10);
    HasFriendT<int> hfi2(20);
    HasFriendT<double> hfdb(10.5);
    report(hfi1);  // 生成 report(HasFriendT<int> &)
    report(hfi2);  // 生成 report(HasFriendT<int> &)
    report(hfdb);  // 生成 report(HasFriendT<double> &)
    cout << "counts<int>() 输出:\n";
    counts<int>();
    cout << "counts<double>() 输出:\n";
    counts<double>();
    
    return 0;
}
