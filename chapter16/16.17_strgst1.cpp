// strgstl.cpp -- 将STL应用于字符串处理
#include <iostream>     // 输入输出流
#include <string>      // 字符串类
#include <algorithm>   // 算法库，包含sort和next_permutation

int main()
{
    using namespace std;
    string letters;    // 定义字符串变量用于存储输入
    
    // 提示用户输入字母组合
    cout << "请输入字母组合（输入quit退出）: ";
    
    // 当成功读取输入且输入不是"quit"时继续循环
    while (cin >> letters && letters != "quit")
    {
        // 显示当前字符串的全排列
        cout << "字符串 " << letters << " 的全排列如下：" << endl;
        
        // 首先对字符串进行排序，确保从最小排列开始
        sort(letters.begin(), letters.end());
        cout << letters << endl;
        
        // 使用next_permutation不断获取下一个排列并输出
        while (next_permutation(letters.begin(), letters.end()))
            cout << letters << endl;
            
        // 提示用户输入下一组字母
        cout << "请输入下一组字母（输入quit退出）: ";
    }
    
    cout << "程序结束。\n";
    return 0;
}
