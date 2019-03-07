#include "outfile.h"
#include <iostream>

using namespace std;

//Kimeneti fájl megnyitása, sikertelen megnyitás esetén hibát dobunk

OutFile::OutFile(const std::string &fileName) {
    f.open(fileName.c_str());
    if(f.fail()) {
        cerr << fileName << " file nem jott letre!\n";
        throw FILE_ERROR;
    }
}

void OutFile::write(const Kaktusz &dx) {
    f << dx.nev << " " << dx.haza << " " << dx.szin << " " << dx.meret << endl;
}

//fájlba kiírás
