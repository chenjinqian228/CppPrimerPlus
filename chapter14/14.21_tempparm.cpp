// tempparm.cpp - 模板作为参数的示例
#include <iostream>
#include "14.15_stcktp1.h"

template <template <typename T> class Thing>
class Crab
{
private:
    Thing<int> s1;
    Thing<double> s2;
public:
    Crab() {};
    // 假定传入的模板类具有 push() 和 pop() 成员函数
    bool push(int a, double x) { return s1.push(a) && s2.push(x); }
    bool pop(int & a, double & x) { return s1.pop(a) && s2.pop(x); }
};

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    Crab<Stack> nebula;
    // Stack 必须匹配模板参数 <typename T> class thing 的形式
    int ni;
    double nb;
    cout << "请输入整数和浮点数对，例如 4 3.5 (输入 0 0 结束):\n";
    while (cin>> ni >> nb && ni > 0 && nb > 0)
    {
        if (!nebula.push(ni, nb))
            break;
    }

    while (nebula.pop(ni, nb))
        cout << ni << ", " << nb << endl;
    cout << "完成。\n";

    return 0;
}
