// functor.cpp -- 使用函子
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

template<class T>  // functor类定义operator()()
class TooBig
{
private:
    T cutoff;
public:
    TooBig(const T & t) : cutoff(t) {}
    bool operator()(const T & v) { return v > cutoff; }
};

void outint(int n) { std::cout << n << " "; }

int main()
{
    using std::list;
    using std::cout;
    using std::endl;

    TooBig<int> f100(100); // 限制 = 100
    int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    list<int> yadayada(vals, vals + 10); // 范围构造函数
    list<int> etcetera(vals, vals + 10);
    
    // C++0x可以使用以下方式替代
    // list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    // list<int> etcetera {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};

    cout << "原始列表:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;
    yadayada.remove_if(f100);               // 使用命名函数对象
    etcetera.remove_if(TooBig<int>(200));   // 构造一个函数对象
    cout <<"修剪后的列表:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;
    
    return 0;
}
