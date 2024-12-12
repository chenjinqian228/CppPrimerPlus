// tempmemb.cpp -- 模板成员示例
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class beta
{
private:
    template <typename V>    // 嵌套的模板类成员
    class hold              // 持有类
    {
    private:
        V val;             // 存储值
    public:
        // 构造函数，默认值为0
        hold(V v = 0) : val(v) {}
        // 显示值
        void show() const { cout << val << endl; }
        // 返回存储的值
        V Value() const { return val; }
    };
    
    hold<T> q;              // 模板对象，类型为T
    hold<int> n;            // 模板对象，类型为int
public:
    // 构造函数，初始化两个hold对象
    beta(T t, int i) : q(t), n(i) {}
    
    // 模板方法
    template<typename U>
    // 计算 (n值 + q值) * u / t
    U blab(U u, T t) { return (n.Value() + q.Value()) * u / t; }
    
    // 显示两个hold对象的值
    void Show() const { q.show(); n.show(); }
};

int main()
{
    // 创建一个beta对象，T被设置为double类型
    beta<double> guy(3.5, 3);
    cout << "T被设置为double类型\n";
    guy.Show();
    cout << "V先被设置为T(即double)，然后V被设置为int\n";
    cout << guy.blab(10, 2.3) << endl;    // U被设置为int
    cout << "U被设置为int类型\n";
    cout << guy.blab(10.0, 2.3) << endl;  // U被设置为double
    cout << "U被设置为double类型\n";
    cout << "程序结束\n";
    return 0;
}
