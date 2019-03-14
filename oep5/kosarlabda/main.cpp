/*
* Feladat:
* Egy szekvenciális input fájlban kosárlabda mérkőzések eredményeit rögzítették.
* A fájl egy sora egy csapat meccseit írja le. A sor formátuma a következő:
* Elsőként a csapat neve van megadva, a név egy vagy több részből áll, szóköz/tab
* választja el a név részeit, tudjuk, hogy a név részei biztosan nem számmal kezdődő
* szövegek
* Utána következnek a meccsek eredményei: saját_pontok-ellenfél_pontjai formában.
* Például:
* Hiros Varos SC utanpotlas 10-20 52-30 34-47
* A fájl sorainak számát nem ismerjük (üres sor nem lehet a fájlban).
* Feladatok:
* (1)
* A csapatokról készítsük el a következő tabellát (táblázatot) egy output fájlba:
* csapat neve hány_mérkőzést_játszott nyert_mérkőzés vesztett_mérkőzés döntetlen_mérkőzés dobott_pont kapott_pont
* Például:
* Hiros Varos SC utanpotlas 3 1 2 0 96 97
* (2)
* Melyik csapat dobta a legtöbb pontot?
*
* Az input fájlról nem tehető fel, hogy hibátlan, beolvasás közben szűrjünk minél több hibát!
*/

#include <iostream>
#include <stdlib.h>
#include "common.h"
#include "seqinfile.h"
#include "seqoutfile.h"

using namespace std;

int main()
{
    cout<<"Kosarlabda bajnoksag\n";
    try{
        string fname;
        cout<<"Add meg a fajl nevet:"; cin>>fname;
        Tabella z, maxelem;
        TabellaEnor t(fname);
        SeqOutFile y;
        int max = -1;
        for (t.First(); !t.End(); t.Next()) {
            z = t.Current();
            y.Write(z);

            if (z.ossz_dobott > max) {
                max = z.ossz_dobott;
                maxelem = z;
            }
        }

        if (max == -1) {
            cout << "Ures a fajl, vagy minden sora hibas!\n";
        } else {
            cout << "Legtobb dobott pont: " << max << endl;
            cout << "Csapat neve: " << maxelem.name << endl;
        }

    }catch (TabellaEnor::Errors err){
         cerr<<"Problema van inp.txt fajllal, a feldolgozas leall!\n";
         exit(1);
    }catch (SeqOutFile::Errors err)
    {
         cerr<<"Problema van az output fajllal, a feldolgozas leall!\n";
         exit(1);
    }

    return 0;
}


