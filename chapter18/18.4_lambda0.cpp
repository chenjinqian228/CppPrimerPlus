// lambda0.cpp -- 使用lambda表达式
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

const long Size1 = 39L;
const long Size2 = 100 * Size1;
const long Size3 = 100 * Size2;
bool f3(int x) { return x % 3 == 0; }
bool f13(int x) { return x % 13 == 0; }
int main()
{
    using std::cout;
    std::vector<int> numbers(Size1);
    std::srand(std::time(0));
    std::generate(numbers.begin(), numbers.end(), std::rand);

    // 使用函数指针
    cout << "样本大小 = " << Size1 << '\n';

    int count3 = std::count_if(numbers.begin(), numbers.end(), f3);
    cout << "能被3整除的数的个数: " << count3 << '\n';
    int count13 = std::count_if(numbers.begin(), numbers.end(), f13);
    cout << "能被13整除的数的个数: " << count13 << '\n';

    // 增加数字数量
    numbers.resize(Size2);
    std::generate(numbers.begin(), numbers.end(), std::rand);
    cout << "样本大小 = " << Size2 << '\n';

    // 使用函数对象
    class f_mod
    {
    private:
        int dv;

    public:
        f_mod(int d = 1) : dv(d) {}
        bool operator()(int x) { return x % dv == 0; }
    };
    count3 = std::count_if(numbers.begin(), numbers.end(), f_mod(3));
    cout << "能被3整除的数的个数: " << count3 << '\n';
    count13 = std::count_if(numbers.begin(), numbers.end(), f_mod(13));
    cout << "能被13整除的数的个数: " << count13 << '\n';

    // 增加数字数量
    numbers.resize(Size3);
    std::generate(numbers.begin(), numbers.end(), std::rand);
    cout << "样本大小 = " << Size3 << '\n';
    // 使用lambda表达式
    count3 = std::count_if(numbers.begin(), numbers.end(), [](int x)
                           { return x % 3 == 0; });
    cout << "能被3整除的数的个数: " << count3 << '\n';
    count13 = std::count_if(numbers.begin(), numbers.end(), [](int x)
                            { return x % 13 == 0; });
    cout << "能被13整除的数的个数: " << count13 << '\n';
    return 0;
}
