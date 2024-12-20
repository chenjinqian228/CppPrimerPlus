// smrtptrs.cpp -- 使用三种智能指针
// 需要支持C++11的shared_ptr和unique_ptr
#include <iostream>
#include <string>
#include <memory>

class Report
{
private:
    std::string str;
public:
    Report(const std::string s) : str(s) 
        { std::cout << "对象已创建!\n"; }
    ~Report() { std::cout << "对象已删除!\n"; }
    void comment() const { std::cout << str << "\n"; }
};

int main()
{
    {
        std::auto_ptr<Report> ps (new Report("使用auto_ptr"));
        ps->comment();   // 使用->调用成员函数
    }
    {
        std::shared_ptr<Report> ps (new Report("使用shared_ptr")); 
        ps->comment();
    }
    {
        std::unique_ptr<Report> ps (new Report("使用unique_ptr"));
        ps->comment();
    }
    return 0;
}
