#include <iostream>
#include <string>

int main()
{
    using namespace std;

    // 1. 普通字符串 - 需要转义字符
    string normal = "First line\nSecond line\tTabbed";

    // 2. 原始字符串 - 不需要转义字符
    string raw1 = R"(First line
Second line    Tabbed)";

    // 3. 包含引号的原始字符串
    string raw2 = R"(They said "hello" to me)";

    // 4. 包含括号的原始字符串 - 使用自定义分隔符
    string raw3 = R"==(文件路径是: C:\Program Files\(x86)\)==";

    // 5. 常见用例：正则表达式
    string regex = R"((\d+)-(\d+)-(\d+))";

    // 6. 常见用例：多行SQL语句
    string sql = R"(
        SELECT *
        FROM users
        WHERE age > 18
        ORDER BY name
    )";

    cout << "普通字符串:\n"
         << normal << "\n\n";
    cout << "原始字符串1:\n"
         << raw1 << "\n\n";
    cout << "原始字符串2:\n"
         << raw2 << "\n\n";
    cout << "原始字符串3:\n"
         << raw3 << "\n\n";
    cout << "正则表达式:\n"
         << regex << "\n\n";
    cout << "SQL语句:\n"
         << sql << "\n";

    return 0;
}
