#include "infile.h"
#include <iostream>
#include <sstream>

using namespace std;

//Fájl megnyitása
//Sikertelen megnyitáskor hibát dobunk

InFile::InFile(const std::string &fileName) noexcept(false) {
    f.open(fileName.c_str());
    if (f.fail()) {
        cerr << fileName << " file nem talalhato!\n";
        throw FILE_ERROR;
    }
}

void InFile::read(Status &sx, Kaktusz &dx) {
    std::string row;
    getline(f, row);

    if (!f.fail()) {
        sx = norm;
        stringstream inp(row);
        inp >> dx.nev >> dx.haza >> dx.szin >> dx.meret;
    } else {
        sx = abnorm;
    }
}
//Read művelet megvalósítása
