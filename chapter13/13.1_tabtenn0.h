// tabtenn0.h -- 一个乒乓球基类
#ifndef TABTENN0_H_
#define TABTENN0_H_

#include <string>
using std::string;

// 简单的基类
class TableTennisPlayer
{
private:
    string firstname;
    string lastname;
    bool hasTable;
public:
    TableTennisPlayer(const string & fn = "none", 
                      const string & ln = "none", bool ht = false);
    void Name() const;
    bool HasTable() const { return hasTable; }
    void ResetTable(bool v) { hasTable = v; }
};

#endif
