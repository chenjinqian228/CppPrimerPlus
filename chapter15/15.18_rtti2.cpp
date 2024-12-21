// rtti2.cpp -- 使用dynamic_cast、typeid和type_info
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
using namespace std;

class Grand
{
private:
    int hold;
public:
    Grand(int h = 0) : hold(h) {}
    virtual void Speak() const { cout << "我是一个grand类!\n";}
    virtual int Value() const { return hold; }
}; 

class Superb : public Grand
{
public:
    Superb(int h = 0) : Grand(h) {}
    void Speak() const {cout << "我是一个superb类!!\n"; }
    virtual void Say() const
        { cout << "我持有superb值 " << Value() << "!\n";}
};

class Magnificent : public Superb
{
private:
    char ch;
public:
    Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) {}
    void Speak() const {cout << "我是一个magnificent类!!!\n";}
    void Say() const {cout << "我持有字符 " << ch <<
               " 和整数 " << Value() << "!\n"; }
};

Grand * GetOne();

int main()
{
    srand(time(0));
    Grand * pg;
    Superb * ps;
    for (int i = 0; i < 5; i++)
    {
        pg = GetOne();
        cout << "现在处理类型 " << typeid(*pg).name() << ".\n";
        pg->Speak();
        if( ps = dynamic_cast<Superb *>(pg))
            ps->Say();
        if (typeid(Magnificent) == typeid(*pg))
            cout << "是的,你真的很magnificent.\n";
    }
    return 0;
}

Grand * GetOne()    // 随机生成三种对象之一
{
    Grand * p;
    switch( rand() % 3)
    {
        case 0: p = new Grand(rand() % 100);
                break;
        case 1: p = new Superb(rand() % 100);
                break;
        case 2: p = new Magnificent(rand() % 100, 'A' + rand() % 26);
                break;
    }
    return p;
}
