// file1.cpp -- 三文件程序示例
#include <iostream>
#include "coordin.h" // 结构模板和函数原型
#include "9.3_file2.cpp"
using namespace std;

int main()
{
    rect rplace;      // 声明直角坐标变量
    polar pplace;     // 声明极坐标变量
    
    cout << "请输入 x 和 y 的值: ";
    while (cin >> rplace.x >> rplace.y)    // 巧妙使用 cin
    {
        pplace = rect_to_polar(rplace);    // 将直角坐标转换为极坐标
        show_polar(pplace);                // 显示极坐标结果
        cout << "请输入下一组数字（输入q退出）: ";
    }
    cout << "再见！\n";
    return 0;
}
