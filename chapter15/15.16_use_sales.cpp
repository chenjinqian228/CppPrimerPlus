// use_sales.cpp -- 嵌套异常
#include <iostream>
#include "15.14_sales.h"
#include "15.15_sales.cpp"

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double vals1[12] = {
        1220, 1100, 1122, 2212, 1232, 2334,
        2884, 2393, 3302, 2922, 3002, 3544
    };

    double vals2[12] = {
        12, 11, 22, 21, 32, 34,
        28, 29, 33, 29, 32, 35
    };

    Sales sales1(2011, vals1, 12);
    LabeledSales sales2("博客之星", 2012, vals2, 12);

    cout << "第一个try块:\n";
    try
    {
        int i;
        cout << "年份 = " << sales1.Year() << endl;
        for (i = 0; i < 12; ++i)
        {
            cout << sales1[i] << ' ';
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "年份 = " << sales2.Year() << endl;
        cout << "标签 = " << sales2.Label() << endl;
        for (i = 0; i <= 12; ++i)
        {
            cout << sales2[i] << ' ';
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "第一个try块结束.\n";
    }
    catch(LabeledSales::nbad_index & bad)
    {
        cout << bad.what();
        cout << "公司: " << bad.label_val() << endl;
        cout << "错误索引: " << bad.bi_val() << endl;
    }
    catch(Sales::bad_index & bad)
    {
        cout << bad.what();
        cout << "错误索引: " << bad.bi_val() << endl;
    }
    cout << "\n下一个try块:\n";
    try
    {
        sales2[2] = 37.5;
        sales1[20] = 23345;
        cout << "第二个try块结束.\n";
    }
    catch(LabeledSales::nbad_index & bad)
    {
        cout << bad.what();
        cout << "公司: " << bad.label_val() << endl;
        cout << "错误索引: " << bad.bi_val() << endl;
    }
    catch(Sales::bad_index & bad)
    {
        cout << bad.what();
        cout << "错误索引: " << bad.bi_val() << endl;
    }
    cout << "完成\n";
    return 0;
}
