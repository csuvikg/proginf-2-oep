#include <string>
#include <iostream>
#include <iomanip>
#include "seqoutfile.h"

using namespace std;

//Feladat:    Eredm�ny f�jl megnyit�sa
//Bemenet:    string fname - sz�veges �llom�ny neve
//Kimenet:    ofstream g   - l�trehozott szekvenci�lis output f�jl
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

//Feladat:    Tabella egy sor�nak ki�r�sa a szekvenci�lis outputf�jlba t�bl�zatos elrendez�sben
//Bemenet:    Tabella dy  - tabella egy sor�nak adatai
//            ofstream g  - tabella sorait tartalmaz� szekvenci�lis outputf�jl
//Kimenet:    ofstream g  - tabella sorait tartalmaz� szekvenci�lis outputf�jl
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

