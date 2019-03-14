#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED
#include <vector>

///A bemeneti f�jl egy sor�b�l beolvasott adatokat t�rol� rekord t�pus
struct Csapat{
    std::string name;
    std::vector<int> dobott;
    std::vector<int> kapott;
};

///A tabella egy sor�nak adatait t�rol� rekord t�pus
struct Tabella{
    std::string name;
    int db;
    int nyert;
    int dontetlen;
    int ossz_dobott;
    int ossz_kapott;
};


#endif // COMMON_H_INCLUDED
