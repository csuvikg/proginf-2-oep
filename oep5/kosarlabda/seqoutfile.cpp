#include <string>
#include <iostream>
#include <iomanip>
#include "seqoutfile.h"

using namespace std;

//Feladat:    Eredmány fájl megnyitása
//Bemenet:    string fname - szöveges állomány neve
//Kimenet:    ofstream g   - létrehozott szekvenciális output fájl
SeqOutFile::SeqOutFile(string fname)
{
    if ( fname.size()<1 ) {
        cout<< "Add meg a kimenet fajl nevet:" ;
        cin>>fname;
    }
    g.open(fname.c_str());
    if ( g.fail() ){
        cerr<< "Nem sikerult letrehozni a fajlt" <<endl;
        throw FILEOPENERROR;
    }
}

//Feladat:    Tabella egy sorának kiírása a szekvenciális outputfájlba táblázatos elrendezésben
//Bemenet:    Tabella dy  - tabella egy sorának adatai
//            ofstream g  - tabella sorait tartalmazó szekvenciális outputfájl
//Kimenet:    ofstream g  - tabella sorait tartalmazó szekvenciális outputfájl
void SeqOutFile::Write(const Tabella &dy)
{
    string csnev(dy.name);
    while(csnev.size()<20) csnev+=" ";
    g<<csnev
    <<setw(5)<<dy.db
    <<setw(5)<<dy.nyert
    <<setw(5)<<dy.db-dy.nyert-dy.dontetlen
    <<setw(5)<<dy.dontetlen
    <<setw(6)<<dy.ossz_dobott
    <<setw(6)<<dy.ossz_kapott
    <<"\n";
}

