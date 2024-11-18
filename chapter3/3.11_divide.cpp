// divide.cpp -- 整数和浮点数除法示例
#include <iostream>
int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);  // 设置固定小数点格式
    
    // 整数除法
    cout << "整数除法: 9/5 = " << 9 / 5 << endl;
    
    // 浮点数除法
    cout << "浮点数除法: 9.0/5.0 = " << 9.0 / 5.0 << endl;
    
    // 混合除法（整数和浮点数）
    cout << "混合除法: 9.0/5 = " << 9.0 / 5 << endl;
    
    // 使用double类型常量的除法
    cout << "double常量: 1e7/9.0 = " << 1.e7 / 9.0 << endl;
    
    // 使用float类型常量的除法
    cout << "float常量: 1e7f/9.0f = " << 1.e7f / 9.0f << endl;
    
    return 0;
}
