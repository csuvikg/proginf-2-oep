#include <iostream>
#include "library/enumerator.hpp"
#include "library/linsearch.hpp"
#include "library/maxsearch.hpp"
#include "library/counting.hpp"
#include "library/seqinfileenumerator.hpp"
#include "library/stringstreamenumerator.hpp"

/// Input fájl szerkezete:
/// a fájl egy sora egy hallgató által egy tárgyból a megszerzett jegyeket írja le:
/// hallgató neve (egy szóközök nélküli string), tárgy neve (egy szóközök nélküli string)
///      majd a jegyek:(komment,jegy) párosok következnek, például:
/// Aladar OEP 1pzh 2 1gzh 1 2pzh 4 2gzh 5 bead 5
///
/// egy hallgatóhoz több tárgy is tartozik
/// a fájl kurzus szerint rendezett

/// Kérdés: Listázzuk ki kurzusonként, hányan teljesítették 3,5 feletti átlaggal a tárgyat
/// (a teljesítéshez az kell, hogy minden jegye legalább 2-es legyen)?
/// Terv: soron belül átlag számítás, volt-e 1-es: összegzés
/// Egyedi felsoroló megszámolja azon 3,5-nél jobb átlagú hallgatókat, akiknek minden jegyük legalább 2-es
/// összegzéssel elkészítjük a listát

using namespace std;



int main()
{
    try
    {

     }
    catch (...)
    {
        cout << "A fajl nem talalhato.\n";
    }
    return 0;
}
