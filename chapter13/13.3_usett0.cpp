// usett0.cpp -- 使用基类
#include <iostream>
#include "13.1_tabtenn0.h"
#include "13.2_tabtenn0.cpp"

int main(void)
{
    using std::cout;
    TableTennisPlayer player1("Chuck", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);
    
    player1.Name();
    if (player1.HasTable())
        cout << ": 有一张球桌。\n";
    else
        cout << ": 没有球桌。\n";
    player2.Name();
    if (player2.HasTable())
        cout << ": 有一张球桌。\n"; 
    else
        cout << ": 没有球桌。\n";

    return 0;
}
