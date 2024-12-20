// vect2.cpp -- 方法和迭代器
#include <iostream>
#include <string>
#include <vector>

struct Review
{
    std::string title;
    int rating;
};

bool FillReview(Review &rr);
void ShowReview(const Review &rr);

int main()
{
    using std::cout;
    using std::vector;
    vector<Review> books;
    Review temp;
    while (FillReview(temp))
        books.push_back(temp);
    int num = books.size();
    if (num > 0)
    {
        cout << "谢谢。您输入了以下 "
             << books.size() << " 个评分:\n"
             << "评分\t书名\n";
        for (int i = 0; i < num; i++)
            ShowReview(books[i]);
        cout << "重述:\n"
             << "评分\t书名\n";

        vector<Review>::iterator pr;
        for (pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);
        vector<Review> oldBooks(books); // 调用复制构造函数
        if (num > 3)
        {
            books.erase(books.begin() + 1, books.begin() + 3);
            std::cout << "删除后:\n";
            for (pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);
        }
        books.swap(oldBooks); // 仅交换向量内容
        cout << "将 oldBooks 与 books 交换:\n";
        for (pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);
    }
    else
        cout << "未输入任何内容，未获得任何内容。\n";
    return 0;
}

bool FillReview(Review &rr)
{
    std::cout << "请输入书名 (输入 quit 退出): ";
    std::getline(std::cin, rr.title);
    if (rr.title == "quit")
        return false;
    std::cout << "请输入书评分: ";
    std::cin >> rr.rating;
    if (!std::cin)
        return false;
    // 清除输入行的剩余内容
    while (std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const Review &rr)
{
    std::cout << rr.rating << "\t" << rr.title << std::endl;
}
