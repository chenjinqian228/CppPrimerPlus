#include <iostream>

int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield); // 设置为定点表示法
    float tub = 10.0 / 3.0;    // float类型，单精度浮点数
    double mint = 10.0 / 3.0;   // double类型，双精度浮点数
    const float million = 1.0e6;  // 一百万

    cout << "tub = " << tub;
    cout << ", 一百万个tub = " << million * tub;
    cout << ",\n一千万个tub = " << 10 * million * tub << endl;

    cout << "mint = " << mint;
    cout << ", 一百万个mint = " << million * mint;
    cout << ",\n一千万个mint = " << 10 * million * mint << endl;
    return 0;
}
