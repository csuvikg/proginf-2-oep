#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED
#include <vector>

///A bemeneti fájl egy sorából beolvasott adatokat tároló rekord típus
struct Csapat{
    std::string name;
    std::vector<int> dobott;
    std::vector<int> kapott;
};

///A tabella egy sorának adatait tároló rekord típus
struct Tabella{
    std::string name;
    int db;
    int nyert;
    int dontetlen;
    int ossz_dobott;
    int ossz_kapott;
};


#endif // COMMON_H_INCLUDED
