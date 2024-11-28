#include <iostream>
using namespace std;

int main() {
    int rats = 101;
    int *pt = &rats;
    int & rodents = *pt;
    int bunnies = 50;
    pt = &bunnies;

    cout << "rats = " << rats << endl;
    cout << "rodents = " << rodents << endl;
    cout << "bunnies = " << bunnies << endl;
    cout << "*pt = " << *pt << endl;

    // 打印地址以验证关系
    cout << "\n地址：" << endl;
    cout << "&rats = " << &rats << endl;
    cout << "&rodents = " << &rodents << endl;
    cout << "&bunnies = " << &bunnies << endl;
    cout << "pt = " << pt << endl;

    return 0;
}
