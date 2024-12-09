#include <iostream>
#include <string>
#include "13.7_brass.h"
#include "13.8_brass.cpp"
const int CLIENTS = 4;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    // 创建指向Brass对象的指针数组
    Brass * p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;

    // 循环获取每个客户的信息
    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "请输入客户姓名: ";
        getline(cin,temp);
        cout << "请输入客户账号: ";
        cin >> tempnum;
        cout << "请输入开户余额: ￥";
        cin >> tempbal;
        cout << "输入1代表普通账户 "
            << "输入2代表高级账户: ";
        while (cin >> kind && (kind != '1' && kind != '2'))
            cout <<"请输入1或2: ";
        if (kind == '1')
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        else
        {
            double tmax, trate;
            cout << "请输入透支限额: ￥";
            cin >> tmax;
            cout << "请输入利率 "
                << "(以小数形式): ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal,
                                        tmax, trate);
        }
        while (cin.get() != '\n')
            continue;
    }
    cout << endl;
    // 显示所有账户信息
    for (int i = 0; i < CLIENTS; i++)
    {
        p_clients[i]->ViewAcct();
        cout << endl;
    }
              
    for (int i = 0; i < CLIENTS; i++)
    {
        delete p_clients[i];  // free memory
    }
    cout << "Done.\n";
    return 0;
}
