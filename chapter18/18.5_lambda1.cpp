// lambda1.cpp -- 使用捕获变量的示例
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

const long Size = 390000L;

int main()
{
    using std::cout;
    std::vector<int> numbers(Size);
    
    // 初始化随机数生成器
    std::srand(std::time(0));
    // 生成随机数填充vector
    std::generate(numbers.begin(), numbers.end(), std::rand);
    cout << "样本大小 = " << Size << '\n';

    // 使用lambda表达式
    // 方法1：使用count_if统计被3整除的数量
    int count3 = std::count_if(numbers.begin(), numbers.end(),
            [](int x){return x % 3 == 0;});
    cout << "能被3整除的数字数量：" << count3 << '\n';
    
    // 方法2：使用for_each和引用捕获统计被13整除的数量
    int count13 = 0;
    std::for_each(numbers.begin(), numbers.end(),
            [&count13](int x){count13 += x % 13 == 0;});
    cout << "能被13整除的数字数量：" << count13 << '\n';
    
    // 方法3：使用单个lambda同时统计被3和13整除的数量
    count3 = count13 = 0;
    std::for_each(numbers.begin(), numbers.end(),
            [&](int x){count3 += x % 3 == 0; count13 += x % 13 == 0;});
    cout << "能被3整除的数字数量：" << count3 << '\n';
    cout << "能被13整除的数字数量：" << count13 << '\n';
    
    return 0;
}
