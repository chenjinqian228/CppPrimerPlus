// usedma.cpp -- 继承、友元和动态内存分配
#include <iostream>
#include "13.14_dma.h"
#include "13.15_dma.cpp"

int main() {
    using std::cout;
    using std::endl;

    baseDMA shirt("Portabelly", 8);
    lacksDMA balloon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo Keys", 5);

    cout << "显示 baseDMA 对象:\n";
    cout << shirt << endl;

    cout << "显示 lacksDMA 对象:\n"; 
    cout << balloon << endl;

    cout << "显示 hasDMA 对象:\n";
    cout << map << endl;

    lacksDMA balloon2(balloon);
    cout << "lacksDMA 复制的结果:\n";
    cout << balloon2 << endl;

    hasDMA map2;
    map2 = map;
    cout << "hasDMA 赋值的结果:\n";
    cout << map2 << endl;

    return 0;
}
