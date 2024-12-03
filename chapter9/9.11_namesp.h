// namesp.h - 命名空间头文件
#include <string>

// 创建人员（pers）和债务（debts）命名空间
namespace pers // 人员命名空间
{
    struct Person // 人员结构体
    {
        std::string fname;    // 名字
        std::string lname;    // 姓氏
    };
    void getPerson(Person &);         // 获取人员信息
    void showPerson(const Person &);  // 显示人员信息
}

namespace debts // 债务命名空间
{
    using namespace pers;     // 引入 pers 命名空间
    struct Debt // 债务结构体
    {
        Person name;         // 债务人信息
        double amount;       // 债务金额
    };
    void getDebt(Debt &);                    // 获取债务信息
    void showDebt(const Debt &);             // 显示债务信息
    double sumDebts(const Debt ar[], int n);  // 计算债务总额
}
