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
        cerr<<fname<<" nem nyithato meg!\n";
        throw MISSINGFILE;
    }
}

//Read művelet megvalósítása
void InFile::read(Status &sx, adat &dx)
{
    std::string sor;
    f.clear();
    getline(f, sor);
    if (!f.fail() && sor!="")
    {
        sx = norm;
        std::stringstream inp(sor);
        inp >> dx.id; //vadász azonosítója
        inp >> dx.date; //vadászat dátuma
        string s; float r;
        dx.fajta.clear(); //tömbök feltöltése előtt legyen mindig clear()
        dx.suly.clear();
        while(inp>>s>>r)
        {
            dx.fajta.push_back(s); //zsákmány neve
            dx.suly.push_back(r); //zsákmány súlya
        }
    }
    else{
        sx = abnorm;
    }
}
