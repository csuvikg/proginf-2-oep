#include "seqinfile.h"
#include <sstream>
#include <iostream>

using namespace std;

TabellaEnor::TabellaEnor(string fname)
{
    if(fname.size()<1) fname="inp.txt";
    f.open(fname.c_str());
    if(f.fail()){
        throw MISSINGFILE;
    }
}

void TabellaEnor::First()
{
    Next();
}

void TabellaEnor::Next()
{
    bool hiba;
    do {
        hiba = false;
        try {
            read();
        } catch (Errors err) {
            cerr << "Hibas rekord: " << sor << endl;
            switch (err) {
            case MISSINGRESULT:
                cerr << "Nincs eredmenye a csapatnak!\n";
                break;
            case WRONGRESULTFORMAT:
                cerr << "Rossz az eredmeny formatuma!\n";
                break;
            }
            hiba = true;
            cerr << "A rekord kimarad a feldolgozasbol.\n\n";
        }
    } while (hiba);
    if (!End()) tabellaz();
}



void TabellaEnor::read()
{
    f.clear();
    getline(f, sor);
    if (!f.fail()) {
        sf = norm;
        istringstream ss(sor);
        // Nev beolvasasa
        elem.name = "";
        string str;
        for (ss >> str; !ss.fail() && !(isdigit(str[0]) || str[0] == '-'); ss >> str) {
            if (elem.name != "") elem.name += ' ';
            elem.name += str;
        }
        // Ha itt vege, akkor nem volt eredmeny
        if (ss.fail()) throw MISSINGRESULT;

        // Eredmenyek feldolgozasa
        elem.dobott.resize(0);
        elem.kapott.resize(0);

        // Mar beolvastuk az elsot
        for (; !ss.fail(); ss >> str) {
            int c = 0;
            for (char ch : str) if (isdigit(ch)) ++c;
            if (c != (int) str.size() - 1) throw WRONGRESULTFORMAT;

            unsigned int pos = str.find("-");
            if (pos == string::npos || pos == 0 || pos == str.size() - 1)
                throw WRONGRESULTFORMAT;

            int dob = atoi(str.substr(0, pos).c_str());
            int kap = atoi(str.substr(pos + 1, str.size() - pos - 1).c_str());
            elem.dobott.push_back(dob);
            elem.kapott.push_back(kap);
        }
    } else {
        sf = abnorm;
    }
}

void TabellaEnor::tabellaz()
{
    t.name=elem.name;
    t.db=(int)elem.dobott.size();
    t.nyert=0;
    t.dontetlen=0;
    t.ossz_dobott=0;
    t.ossz_kapott=0;
    for(int i=0;i<(int)elem.dobott.size();i++)
    {
        if(elem.dobott[i]>elem.kapott[i]) ++t.nyert;
        else if(elem.dobott[i]==elem.kapott[i]) ++t.dontetlen;
        t.ossz_dobott+=elem.dobott[i];
        t.ossz_kapott+=elem.kapott[i];
    }
}
