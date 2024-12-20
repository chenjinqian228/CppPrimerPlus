// inserts.cpp -- 演示copy()函数和插入迭代器的使用
#include <iostream>  // 输入输出流
#include <string>    // 字符串类
#include <iterator>  // 迭代器
#include <vector>    // 向量容器
#include <algorithm> // 算法库

// 输出函数：打印字符串并跟随一个空格
void output(const std::string &s) { std::cout << s << " "; }

int main()
{
    using namespace std;
    // 定义三个字符串数组
    string s1[4] = {"fine", "fish", "fashion", "fate"}; // 4个元素的数组
    string s2[2] = {"busy", "bats"};                    // 2个元素的数组
    string s3[2] = {"silly", "singers"};                // 2个元素的数组
    vector<string> words(4);                            // 创建容量为4的字符串向量

    // 使用普通迭代器：将s1数组的所有元素复制到words向量中
    copy(s1, s1 + 4, words.begin());
    // 使用for_each算法遍历并输出words中的所有元素
    for_each(words.begin(), words.end(), output);
    cout << endl; // 换行

    // 构造匿名的尾部插入迭代器对象
    // 将s2数组的元素添加到words向量的末尾
    copy(s2, s2 + 2, back_insert_iterator<vector<string>>(words));
    for_each(words.begin(), words.end(), output);
    cout << endl;

    // 构造匿名的插入迭代器对象
    // 将s3数组的元素插入到words向量的开始位置
    copy(s3, s3 + 2, insert_iterator<vector<string>>(words, words.begin()));
    for_each(words.begin(), words.end(), output);
    cout << endl;
    return 0;
}
