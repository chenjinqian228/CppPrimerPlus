// lotto.cpp -- 计算中奖概率
#include <iostream>
// 注意：某些实现可能需要使用 double 而不是 long double
long double probability(unsigned numbers, unsigned picks);

int main()
{
    using namespace std;
    double total, choices;    // 总数和选择数
    cout << "请输入彩票卡上的总数字数量和\n"
         << "需要选择的数字数量:\n";
    
    // 当成功读取输入且选择数不大于总数时继续循环
    while ((cin >> total >> choices) && choices <= total)
    {
        cout << "您中奖的概率是 ";
        cout << probability(total, choices);    // 计算概率
        cout << " 分之一\n";
        cout << "请输入下一组数字 (输入q退出): ";
    }
    cout << "再见\n";
    return 0;
}

// 以下函数用于计算从指定数量(numbers)中
// 选择特定个数(picks)的中奖概率
long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;    // 初始化局部变量
    long double n;
    unsigned p;
    
    // 计算组合数学中的排列数
    for (n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p;
    return result;
}
