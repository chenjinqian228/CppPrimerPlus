// nested.cpp -- 嵌套循环和二维数组
#include <iostream>
const int Cities = 5;      // 城市数量
const int Years = 4;       // 年份数量
int main()
{
    using namespace std;
    const char * cities[Cities] =    // 指针数组
                                    // 指向5个字符串
    {
        "格里布尔城",
        "格里布尔镇",
        "新格里布尔",
        "圣格里布尔",
        "格里布尔景观"
    };

    int maxtemps[Years][Cities] =    // 二维数组
    {
        {96, 100, 87, 101, 105},    // maxtemps[0]的值
        {96, 98, 91, 107, 104},     // maxtemps[1]的值
        {97, 101, 93, 108, 107},    // maxtemps[2]的值
        {98, 103, 95, 109, 108}     // maxtemps[3]的值
    };

    cout << "2008年至2011年的最高温度\n\n";
    for (int city = 0; city < Cities; ++city)
    {
        cout << cities[city] << ":\t";
        for (int year = 0; year < Years; ++year)
            cout << maxtemps[year][city] << "\t";
        cout << endl;
    }
    // cin.get();
    return 0;
}
