#ifndef SEQINFILE_H_INCLUDED
#define SEQINFILE_H_INCLUDED

#include <vector>
#include <fstream>
#include <string>

#include "common.h"

enum Status{abnorm, norm};

class TabellaEnor
{
    public:
        enum Errors{MISSINGFILE,MISSINGRESULT,WRONGRESULTFORMAT};
        TabellaEnor(std::string fname="");
        void First();
        void Next();
        bool End() const { return sf==abnorm;}
        Tabella Current() const { return t; }
    private:
        std::ifstream f;
        Csapat elem;
        Tabella t;
        Status sf;
        std::string sor;
        void read(); ///A fájl egy sorát beolvassa és elem-ben elhelyezi a beolvasott adatokat
        void tabellaz(); ///A beolvasott adatokból elkészíti a tabella egy sorát
};


#endif // SEQINFILE_H_INCLUDED
