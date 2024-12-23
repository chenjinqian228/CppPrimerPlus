// fileio.cpp -- 文件保存示例
#include <iostream> // 在许多系统中不需要这个头文件
#include <fstream> // 文件流操作头文件
#include <string>  // 字符串操作头文件

int main()
{
    using namespace std;
    string filename; // 文件名变量
    
    cout << "请输入新文件的名称: ";
    cin >> filename;
    
    // 创建输出文件流对象并命名为fout
    ofstream fout(filename.c_str());
    
    fout << "仅供您查看！\n";        // 写入文件
    cout << "请输入您的秘密数字: ";  // 在屏幕上显示提示
    float secret;                    // 声明浮点数变量
    cin >> secret;
    fout << "您的秘密数字是 " << secret << endl;
    fout.close();                   // 关闭文件
    
    // 创建输入文件流对象并命名为fin
    ifstream fin(filename.c_str());
    cout << "以下是文件 " << filename << " 的内容:\n";
    char ch;
    while (fin.get(ch))     // 从文件中读取字符
        cout << ch;         // 将字符输出到屏幕
    cout << "完成\n";
    fin.close();           // 关闭文件
    
    return 0;
}
