// placenew1.cpp -- new、定位 new 运算符的使用，没有 delete
#include <iostream>
#include <string>
#include <new>
using namespace std;

const int BUF = 512;

class JustTesting {
private:
    string words;
    int number;
public:
    JustTesting(const string & s = "Just Testing", int n = 0) {
        words = s; number = n; cout << words << " 已构造\n";
    }
    ~JustTesting() { cout << words << " 已销毁\n"; }
    void Show() const { cout << words << ", " << number << endl; }
};

int main() {
    char * buffer = new char[BUF];       // 获取一块内存

    JustTesting *pc1, *pc2;

    pc1 = new (buffer) JustTesting;      // 在缓冲区中放置对象
    pc2 = new JustTesting("堆1", 20);    // 在堆中放置对象
    
    cout << "内存块地址：\n" << "缓冲区: "
         << (void *) buffer << "    堆: " << pc2 << endl;
    cout << "内存内容：\n";
    cout << pc1 << ": ";
    pc1->Show();
    cout << pc2 << ": ";
    pc2->Show();

    JustTesting *pc3, *pc4;
    // 修正定位 new 的位置
    pc3 = new (buffer + sizeof(JustTesting))
                JustTesting("更好的主意", 6);
    pc4 = new JustTesting("堆2", 10);

    cout << "内存内容：\n";
    cout << pc3 << ": ";
    pc3->Show();
    cout << pc4 << ": ";
    pc4->Show();
    
    delete pc2;           // 释放堆1
    delete pc4;           // 释放堆2
    // 显式销毁定位 new 创建的对象
    pc3->~JustTesting(); // 销毁 pc3 指向的对象
    pc1->~JustTesting(); // 销毁 pc1 指向的对象
    delete [] buffer;     // 释放缓冲区
    cout << "完成\n";
    return 0;
}
