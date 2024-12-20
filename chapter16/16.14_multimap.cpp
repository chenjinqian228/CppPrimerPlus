// multimap.cpp -- 使用multimap
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

typedef int KeyType;
typedef std::pair<const KeyType, std::string> Pair;
typedef std::multimap<KeyType, std::string> MapCode;

int main() {
    using namespace std;
    MapCode codes;

    // 填充multimap
    codes.insert(Pair(415, "旧金山"));
    codes.insert(Pair(510, "奥克兰"));
    codes.insert(Pair(718, "布鲁克林"));
    codes.insert(Pair(718, "斯塔滕岛"));
    codes.insert(Pair(415, "圣拉斐尔"));
    codes.insert(Pair(510, "伯克利"));

    cout << "区号415的城市数量: "
         << codes.count(415) << endl;
    cout << "区号718的城市数量: "
         << codes.count(718) << endl;
    cout << "区号510的城市数量: "
         << codes.count(510) << endl;
    
    cout << "区号   城市\n";
    MapCode::iterator it;
    for (it = codes.begin(); it != codes.end(); ++it)
        cout << "    " << (*it).first << "     "
             << (*it).second << endl;

    pair<MapCode::iterator, MapCode::iterator> range = 
        codes.equal_range(718);
    cout << "区号718的城市:\n";
    for (it = range.first; it != range.second; ++it)
        cout << (*it).second << endl;

    return 0;
}
