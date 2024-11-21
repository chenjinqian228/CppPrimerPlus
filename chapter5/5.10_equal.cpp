// equal.cpp -- 相等运算符与赋值运算符的对比
#include <iostream>
int main()
{
    using namespace std;
    // 定义一个包含10个测验分数的数组
    int quizscores[10] = 
        { 20, 20, 20, 20, 20, 19, 20, 18, 20, 20};

    cout << "正确的做法：\n";
    int i;
    // 使用相等运算符(==)检查分数是否等于20
    for (i = 0; quizscores[i] == 20; i++)
        cout << "测验 " << i << " 的分数是20\n";

    // 警告：建议您阅读这个程序而不是实际运行它
    // 因为下面的代码可能导致意外的结果
    cout << "危险且错误的做法：\n";
    // 错误：使用赋值运算符(=)而不是相等运算符(==)
    for (i = 0; quizscores[i] = 20; i++)
        cout << "测验 " << i << " 的分数是20\n";

    return 0;
}
