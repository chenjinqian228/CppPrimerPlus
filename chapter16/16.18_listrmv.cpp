// listrmv.cpp -- 在字符串中应用STL
#include <iostream>
#include <list>
#include <algorithm>

void Show(int); // 显示函数声明
const int LIM = 10; // 定义数组长度常量

int main()
{
    using namespace std; // 使用标准命名空间
    // 初始化一个包含10个整数的数组
    int ar[LIM] = {4, 5, 4, 2, 2, 3, 4, 8, 1, 4};
    // 使用数组初始化list容器la
    list<int> la(ar, ar + LIM);
    // 复制la到lb
    list<int> lb(la);
    
    // 显示原始列表内容
    cout << "原始列表内容：\n\t";
    for_each(la.begin(), la.end(), Show);
    cout << endl;
    
    // 使用list的成员函数remove()删除所有的4
    la.remove(4);
    cout << "使用remove()方法后：\n";
    cout << "la:\t";
    for_each(la.begin(), la.end(), Show);
    cout << endl;
    
    // 使用STL算法remove()
    list<int>::iterator last; // 声明迭代器
    // remove()函数会返回新的逻辑末尾位置
    last = remove(lb.begin(), lb.end(), 4);
    cout << "使用remove()函数后：\n";
    cout << "lb:\t";
    for_each(lb.begin(), lb.end(), Show);
    cout << endl;
    
    // 使用erase()删除remove()后的多余元素
    lb.erase(last, lb.end());
    cout << "使用erase()方法后：\n";
    cout << "lb:\t";
    for_each(lb.begin(), lb.end(), Show);
    cout << endl;
    
    return 0;
}

// 显示函数定义：打印数值并加空格
void Show(int v)
{
    std::cout << v << ' ';
}
