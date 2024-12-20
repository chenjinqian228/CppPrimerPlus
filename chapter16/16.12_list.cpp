// list.cpp -- 使用列表
#include <iostream>
#include <list>
#include <algorithm>

void outint(int n) { std::cout << n << " "; }

int main()
{
    using namespace std;
    list<int> one(5, 2);    // 包含5个2的列表
    int stuff[5] = {1, 2, 4, 8, 6};
    list<int> two;
    two.insert(two.begin(), stuff, stuff + 5);
    int more[6] = {6, 4, 2, 4, 6, 5};
    list<int> three(two);
    three.insert(three.end(), more, more + 6);

    cout << "列表一: ";
    for_each(one.begin(), one.end(), outint);
    cout << endl;
    cout << "列表二: ";
    for_each(two.begin(), two.end(), outint);
    cout << endl;
    cout << "列表三: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl;

    three.remove(2);
    cout << "列表三删除2后: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl;

    three.splice(three.begin(), one);
    cout << "列表三拼接后: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl;
    cout << "列表一: ";
    for_each(one.begin(), one.end(), outint);
    cout << endl;

    three.unique();
    cout << "列表三去重后: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl;

    three.sort();
    three.unique();
    cout << "列表三排序并去重后: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl;

    two.sort();
    three.merge(two);
    cout << "排序后的列表二合并到列表三: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl;
    return 0;
}
