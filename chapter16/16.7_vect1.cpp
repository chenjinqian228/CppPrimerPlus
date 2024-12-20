// vect1.cpp -- 介绍vector模板
#include <iostream>
#include <string>
#include <vector>

const int NUM = 5;

int main()
{
    using std::vector;
    using std::string;
    using std::cin;
    using std::cout;
    using std::endl;

    vector<int> ratings(NUM);
    vector<string> titles(NUM);
    cout << "您将进行 " << NUM 
         << " 个评分 (1-10)\n";
    cout << "请输入电影名称和评分:\n";
    for (int i = 0; i < NUM; i++)
    {
        cout << "输入标题 #" << i + 1 << ": ";
        getline(cin,titles[i]);
        cout << "输入您的评分 (1-10): ";
        cin >> ratings[i];
        cin.get();
    }
    cout << "谢谢。您输入了以下内容:\n"
         << "评分\t电影\n";
    for (int i = 0; i < NUM; i++)
    {
        cout << ratings[i] << "\t" << titles[i] << endl;
    }
    return 0;
}
