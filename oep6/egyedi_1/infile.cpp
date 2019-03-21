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

}
