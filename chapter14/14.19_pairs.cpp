// pairs.cpp -- 定义和使用Pair模板
#include <iostream>
#include <string>

template <class T1, class T2>
class Pair
{
private:
    T1 a;
    T2 b;
public:
    Pair() {}
    Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) { }
    T1 & first();
    T2 & second(); 
    T1 first() const { return a; }
    T2 second() const { return b; }
};

template<typename T1, typename T2>
T1 & Pair<T1, T2>::first()
{
    return a;
}
template<typename T1, typename T2>
T2 & Pair<T1, T2>::second()
{
    return b;
}

int main()
{
    using std::cout;
    using std::endl;
    using std::string;
    Pair<string, int> ratings[4] = 
    {
        Pair<string, int>("紫鸭餐厅", 5),
        Pair<string, int>("杰奎的户外餐厅", 4),
        Pair<string, int>("舒芙蕾咖啡馆", 5),
        Pair<string, int>("伯蒂的小吃", 3)
    };

    int joints = sizeof(ratings) / sizeof(Pair<string, int>);
    cout << "评分:\t 餐厅\n";
    for (int i = 0; i < joints; i++)
        cout << ratings[i].second() << ":\t "
             << ratings[i].first() << endl;
    cout << "哎呀! 修改评分:\n";
    ratings[3].first() = "伯蒂的美味小吃";
    ratings[3].second() = 6;
    cout << ratings[3].second() << ":\t "
         << ratings[3].first() << endl;
    return 0;
}
