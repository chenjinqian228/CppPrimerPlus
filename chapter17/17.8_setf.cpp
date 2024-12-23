// setf.cpp -- 使用setf()函数控制格式化输出
#include <iostream>

int main()
{
    using std::cout;
    using std::endl;
    using std::ios_base;

    int temperature = 63;
    cout << "今日水温：";
    cout.setf(ios_base::showpos);      // 显示正号
    cout << temperature << endl;

    cout << "对我们的编程伙伴来说，这是\n";
    cout << std::hex << temperature << endl;  // 使用十六进制
    cout.setf(ios_base::uppercase);    // 在十六进制中使用大写字母
    cout.setf(ios_base::showbase);     // 使用0X作为十六进制前缀
    cout << "或者写作\n";
    cout << temperature << endl;

    cout << "这是 " << true << "！糟糕 -- 应该写作 ";
    cout.setf(ios_base::boolalpha);    // 设置布尔值使用字母形式显示
    cout << true << "！\n";

    return 0;
}
