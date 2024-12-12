// manyfrnd.cpp -- 模板类的非约束模板友元函数示例
#include <iostream>
using std::cout;
using std::endl;

// 定义模板类 ManyFriend
template <typename T>
class ManyFriend
{
private:
    T item;  // 私有数据成员
public:
    // 构造函数
    ManyFriend(const T & i) : item(i) {}
    
    // 声明非约束模板友元函数
    // 注意：C和D是独立的模板参数，与T无关
    template <typename C, typename D> friend void show2(C &, D &);
};

// 定义非约束模板友元函数
template <typename C, typename D> void show2(C & c, D & d)
{
    // 可以访问不同类型实例的私有成员item
    cout << c.item << ", " << d.item << endl;
}

int main()
{
    // 创建不同类型的ManyFriend对象
    ManyFriend<int> hfi1(10);      // 整型对象，值为10
    ManyFriend<int> hfi2(20);      // 整型对象，值为20
    ManyFriend<double> hfdb(10.5); // 双精度浮点型对象，值为10.5

    // 测试show2函数
    cout << "hfi1, hfi2: ";        // 输出两个整型对象的值
    show2(hfi1, hfi2);
    
    cout << "hfdb, hfi2: ";        // 输出一个double类型和一个int类型对象的值
    show2(hfdb, hfi2);
    
    return 0;
}
