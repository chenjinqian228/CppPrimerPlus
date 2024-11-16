// modulus.cpp -- 使用%运算符将磅转换为英石
#include <iostream>
int main()
{
    using namespace std;
    const int lbs_per_stn = 14;    // 1英石等于14磅
    int lbs;
    
    cout << "Enter your weight in pounds: ";
    cin >> lbs;
    int stone = lbs / lbs_per_stn;      // 计算整数英石
    int pounds = lbs % lbs_per_stn;      // 剩余的磅数
    cout << lbs << " pounds are " << stone 
         << " stone, " << pounds << " pound(s).\n";
    return 0;
}
