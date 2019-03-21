#include "infile.h"
#include <sstream>
#include <iostream>

using namespace std;

//Fájl megnyitása
//Sikertelen megnyitáskor hibát dobunk
InFile::InFile(const string& fname)
{
    f.open(fname.c_str());
    if(f.fail()){
        throw MISSINGFILE;
    }
}

//read művelet
void InFile::read(Status &sx, int &dx)
{
    f >> dx;
    sx = f.fail() ? abnorm : norm;
}

// Egyedi felsorolo impl
void FreqEnor::next() {
    vege = sx == abnorm;
    if (!vege) {
        akt.val = dx;
        akt.db = 0;
        for(; sx == norm && dx == akt.val; x.read(sx, dx)) {
            ++akt.db;
        }
    }
}
