// newexcp.cpp -- bad_alloc异常
#include <iostream>
#include <new>
#include <cstdlib>  // 用于exit(), EXIT_FAILURE
using namespace std;

struct Big
{
    double stuff[20000];
};

int main()
{
    Big * pb;
    try {
        cout << "尝试获取一块大内存:\n";
        pb = new Big[100000000]; // 1,600,000,000 字节
        cout << "通过了new请求:\n";
    }
    catch (bad_alloc & ba)
    {
        cout << "捕获到异常!\n";
        cout << ba.what() << endl;
        exit(EXIT_FAILURE);
    }
    cout << "内存分配成功\n";
    pb[0].stuff[0] = 4;
    cout << pb[0].stuff[0] << endl;
    delete [] pb;
    return 0;
}
