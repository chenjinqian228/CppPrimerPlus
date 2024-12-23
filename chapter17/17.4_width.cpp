// width.cpp -- 使用width方法控制输出宽度
#include <iostream>

int main()
{
    using std::cout;
    // 设置输出宽度为30，并将原始宽度值存储在w中
    int w = cout.width(30);
    cout << "默认字段宽度 = " << w << ":\n";
    
    // 设置宽度为5
    cout.width(5);
    cout << "N" <<'|';
    // 设置宽度为8
    cout.width(8);
    cout << "N * N" << ":\n";

    // 循环输出1、10、100的平方
    for (long i = 1; i <= 100; i *= 10)
    {
        // 第一列宽度为5
        cout.width(5);
        cout << i <<'|';
        // 第二列宽度为8
        cout.width(8);
        cout << i * i << ":\n";
    }

    return 0;
}
