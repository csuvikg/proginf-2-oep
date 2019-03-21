#pragma once

#include <fstream>
#include <string>

enum Status{abnorm,norm};

//Szekvenciális input fájl
class InFile{
public:
    enum Errors{MISSINGFILE};
    InFile(const std::string& fname);
    void read(Status &sx, int &dx);
private:
    std::ifstream f;
};

// Egyedi felsorolo
struct adat {
    int val;
    int db;
};

class FreqEnor {
public:
    FreqEnor(const std::string& fname): x(fname) {}
    void first() { x.read(sx, dx); next(); }
    void next();
    bool end() const { return vege; }
    adat current() const { return akt; }
private:
    InFile x;
    int dx;
    Status sx;
    adat akt;
    bool vege;
};
