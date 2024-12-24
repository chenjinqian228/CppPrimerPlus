// tabtenn0.cpp -- 简单的基类方法
#include "13.1_tabtenn0.h"
#include <iostream>

TableTennisPlayer::TableTennisPlayer(const string & fn, 
    const string & ln, bool ht) : firstname(fn),
        lastname(ln), hasTable(ht) {}

void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " << firstname;
}