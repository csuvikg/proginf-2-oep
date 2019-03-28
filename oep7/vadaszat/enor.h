#pragma once

#include "infile.h"

//Zsakmany felsorolo
struct vadaszat{
    std::string id;
    bool medve;
    float suly;
};

class vadaszatEnor{
public:
    vadaszatEnor(std::string fname): x(fname) {}
    void first() { next(); }
    void next();
    bool end() const { return sx == abnorm; }
    vadaszat current() const { return akt; }

private:
    InFile x;
    adat dx;
    Status sx;
    vadaszat akt;
};

//Vadasz felsoroló

struct vadasz{
    std::string id;
    bool lott;
};

class vadaszEnor{
public:
    vadaszEnor(std::string fname): v(fname) {}
    void first() { v.first(); next(); }
    void next();
    bool end() const { return vege; }
    vadasz current() const { return cur; }
private:
    vadaszatEnor v;
    vadasz cur;
    bool vege;
};
