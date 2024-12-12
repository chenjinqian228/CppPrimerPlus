#ifndef ARRAYTP_H_
#define ARRAYTP_H_

#include <iostream>
#include <cstdlib>

// 数组模板类 - 这是一个模板类,用于创建固定大小的数组
template <class T, int n>
class ArrayTP {
private:
    T ar[n];  // 数组成员 - 存储n个类型为T的元素的数组
public:
    ArrayTP() {};  // 默认构造函数 - 创建一个空数组
    explicit ArrayTP(const T & v);  // 带参数构造函数 - 用指定值初始化所有元素
    virtual T & operator[](int i);  // 重载下标运算符 - 返回引用,可以修改元素
    virtual T operator[](int i) const;  // 重载下标运算符(const版本) - 返回值,不能修改元素
};

// 带参数构造函数定义 - 用指定值v初始化数组的所有元素
template <class T, int n>
ArrayTP<T,n>::ArrayTP(const T & v) {
    for (int i = 0; i < n; i++)
        ar[i] = v;
}

// 重载下标运算符定义 - 检查下标范围并返回数组元素的引用
template <class T, int n>
T & ArrayTP<T,n>::operator[](int i) {
    if (i < 0 || i >= n) {
        std::cerr << "数组下标越界错误: " << i
                  << " 超出范围\n";
        std::exit(EXIT_FAILURE);
    }
    return ar[i];
}

// 重载下标运算符定义(const版本) - 检查下标范围并返回数组元素的值
template <class T, int n>
T ArrayTP<T,n>::operator[](int i) const {
    if (i < 0 || i >= n) {
        std::cerr << "数组下标越界错误: " << i
                  << " 超出范围\n";
        std::exit(EXIT_FAILURE);
    }
    return ar[i];
}

#endif
