// strout.cpp -- 内部格式化（输出）
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    using namespace std;
    ostringstream outstr;    // 创建一个字符串流对象
    
    string hdisk;
    cout << "请输入您的硬盘名称：";
    getline(cin, hdisk);
    
    int cap;
    cout << "硬盘容量是多少GB？";
    cin >> cap;
    
    // 将格式化的信息写入字符串流
    outstr << "硬盘 " << hdisk << " 的容量是 "
          << cap << " GB。\n";
          
    string result = outstr.str();    // 保存结果
    cout << result;                  // 显示内容
    
    return 0;
}
