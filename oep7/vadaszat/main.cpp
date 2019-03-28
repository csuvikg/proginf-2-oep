#include <iostream>
#include "enor.h"

using namespace std;

//Adjuk meg azt a vadászt, aki a legnagyobb medvét lőtte
//Felt. max ker a vadászat felsorolón
bool firstTask(vadaszatEnor& t, vadaszat& elem) {
    bool l=false;
    t.first();

    while (!t.end()) {
        cout << t.current().id << " " << t.current().medve << " " << t.current().suly << endl;
        if (!t.current().medve) {
        } else if (t.current().medve && l) {
            if (t.current().suly > elem.suly) {
                elem = t.current();
            }
        } else {
            l = true;
            elem = t.current();
        }

        t.next();
    }

    return l;
}

//Igaz-e, hogy minden vadász lõtt medvét valamely vadászatán
//Optimista eldöntés a vadász felsorolón
bool secondTask(vadaszEnor& t) {
    bool l=true;
    t.first();

    while (l && !t.end()) {
        cout << t.current().id << ": " << t.current().lott << endl;
        l = t.current().lott;
        t.next();
    }
    return l;
}

int main()
{
    string fname;
    try{
        cout<<"Add meg a fajl nevet:"; cin>>fname;
        //Elsõ feladat
        cout<<"\nElso feladat: adjuk meg azt a vadászt, aki a legnagyobb medvét lőtte.\n";

        vadaszatEnor t(fname);
        vadaszat elem;

        bool l = firstTask(t, elem);
        if(l) {
            cout << "A legnagyobb medvet a " << elem.id << " vadasz lotte: " << elem.suly << endl;
        } else {
            cout<<"Nem talaltam olyan vadaszt, aki medvet lott.\n";
        }
        //Második feladat
        cout<<"\nMasodik feladat: igaz-e hogy mindegyik vadasz lott medvet valamely vadaszaton.\n";

        vadaszEnor t2(fname);
        l = secondTask(t2);

        cout << (l ? "IGAZ" : "HAMIS") << endl;

    }catch(InFile::Errors err)
    {
        if(err==InFile::MISSINGFILE)
        {
            cerr<<fname<<" nem nyithato meg!\n";
        }
    }
    return 0;
}
