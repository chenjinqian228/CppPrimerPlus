// lexcast.cpp -- 简单的浮点数到字符串的转换示例
#include <iostream>
#include <string>
#include "boost/lexical_cast.hpp"

int main()
{
    using namespace std;
    
    cout << "请输入您的体重: ";
    float weight;
    cin >> weight;
    
    string gain = "增加10%后，体重从 ";
    string wt = boost::lexical_cast<string>(weight);  // 将体重转换为字符串
    gain = gain + wt + " 增加到 ";    // 字符串连接操作
    
    weight = 1.1 * weight;            // 计算增加10%后的体重
    gain = gain + boost::lexical_cast<string>(weight) + "。";
    
    cout << gain << endl;
    return 0;
}
