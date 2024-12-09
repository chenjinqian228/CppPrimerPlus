// usebrass3.cpp -- 使用抽象基类的多态示例
#include <iostream>
#include "13.11_acctabc.h"
#include "13.12_acctABC.cpp"
using namespace std;

const int CLIENTS = 4;

int main()
{
    AcctABC * p_clients[CLIENTS];
    string temp;
    long tempnum;
    double tempbal;
    char kind;

    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "请输入客户姓名: ";
        getline(cin,temp);
        cout << "请输入客户账号: ";
        cin >> tempnum;
        cout << "请输入开户余额: $";
        cin >> tempbal;
        cout << "输入1选择Brass账户或"
            << "输入2选择BrassPlus账户: ";
        while (cin >> kind && (kind != '1' && kind != '2'))
            cout << "请输入1或2: ";
        if (kind == '1')
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        else
        {
            double tmax, trate;
            cout << "请输入透支限额: $";
            cin >> tmax;
            cout << "请输入利率"
                << "(小数形式): ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal,
                                        tmax, trate);
        }
        while (cin.get() != '\n')
            continue;
    }
    cout << endl;
    for (int i = 0; i < CLIENTS; i++)
    {
        p_clients[i]->ViewAcct();
        cout << endl;
    }
              
    for (int i = 0; i < CLIENTS; i++)
    {
        delete p_clients[i];  // 释放内存
    }
    cout << "完成。\n";         
    return 0;
}
