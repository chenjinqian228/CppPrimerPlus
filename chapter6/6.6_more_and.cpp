// more_and.cpp -- 使用逻辑AND运算符
#include <iostream>
const char * qualify[4] =        // 字符串指针数组
{                               // 指向以下字符串
    "10,000米赛跑。\n",
    "泥地拔河比赛。\n", 
    "独木舟格斗大赛。\n",
    "投掷馅饼节。\n"
};

int main()
{
    using namespace std;
    int age;
    cout << "请输入您的年龄: ";
    cin >> age;
    int index;

    if (age > 17 && age < 35)
        index = 0;
    else if (age >= 35 && age < 50)
        index = 1;
    else if (age >= 50 && age < 65)
        index = 2;
    else
        index = 3;

    cout << "您适合参加的比赛是：" << qualify[index];
    return 0;
}
