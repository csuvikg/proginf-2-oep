#include <iostream>
#include "library/enumerator.hpp"
#include "library/linsearch.hpp"
#include "library/maxsearch.hpp"
#include "library/counting.hpp"
#include "library/seqinfileenumerator.hpp"
#include "library/stringstreamenumerator.hpp"

/// Input f�jl szerkezete:
/// a f�jl egy sora egy hallgat� �ltal egy t�rgyb�l a megszerzett jegyeket �rja le:
/// hallgat� neve (egy sz�k�z�k n�lk�li string), t�rgy neve (egy sz�k�z�k n�lk�li string)
///      majd a jegyek:(komment,jegy) p�rosok k�vetkeznek, p�ld�ul:
/// Aladar OEP 1pzh 2 1gzh 1 2pzh 4 2gzh 5 bead 5
///
/// egy hallgat�hoz t�bb t�rgy is tartozik
/// a f�jl kurzus szerint rendezett

/// K�rd�s: List�zzuk ki kurzusonk�nt, h�nyan teljes�tett�k 3,5 feletti �tlaggal a t�rgyat
/// (a teljes�t�shez az kell, hogy minden jegye legal�bb 2-es legyen)?
/// Terv: soron bel�l �tlag sz�m�t�s, volt-e 1-es: �sszegz�s
/// Egyedi felsorol� megsz�molja azon 3,5-n�l jobb �tlag� hallgat�kat, akiknek minden jegy�k legal�bb 2-es
/// �sszegz�ssel elk�sz�tj�k a list�t

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
