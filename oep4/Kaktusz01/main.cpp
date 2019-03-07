//Órai feladat:     Feladatgyûjtemény 7. feladat: Egy  szekvenciális  inputfájlban  egyes
//                  kaktuszfajtákról  ismerünk  néhány  adatot:  név,őshaza,  virágszín,  méret.
//                  Válogassuk  ki  egy  szekvenciális  outputfájlba  a  mexikói,  egy másikba a piros virágú kaktuszokat!
//                  Adjuk meg a legnagyobb méretű mexikói kaktuszt.

//Szorgalmi Házi feladat:
//                  Egészítsük ki a fájlt a következő adatokkal
//                  (képzeljük el, hogy a fájl egy kaktuszokat forgalmazó cég nyilvántartása)
//                  egységár (egész), készlet mennyisége (egész)
//                  Oldjuk meg a következő feladatokat (a fájl egyszeri végigolvasásával):
//                  mennyi a készlet összértéke
//                  melyik kaktusz a legdrágább? ha nem egyértelmű, az elsőt adjuk meg (feltehető, hogy nem üres a fájl)
//                  írjuk ki egy output fájlba, azokat, melyeknek a készlete épp nulla
//                  alakítsuk át a main függvényt úgy, hogy hibás fájlnév esetén meg lehessen adni újra a fájlnevet
#include <iostream>

using namespace std;

void Feladat(const string& fajlnev, const string& honnan_szarmazik, const string& virag_szine);

int main()
{
    string fname,viragszin,oshaza;
    /*try{
        cout<<"Honnan szarmazo kaktuszokat vizsgaljak:"; cin>>oshaza;
        cout<<"Add meg a virag szint:"; cin>>viragszin;
        cout<<"Add meg az input fajl nevet:"; cin>>fname;
        Feladat(fname,oshaza,viragszin);
    }catch(InFile::Exceptions err)
    {
        if(err==InFile::FILEERROR)
        {
            cerr<<"Problema van az input fajllal: "<<fname<<endl;
        }else{
            cerr<<"Nem vart hiba.\n";
        }
    }*/
    return 0;
}

//piros virágú valamint Mexikó őshazájú kaktuszok kiválogatása külön fájlokba
//output fájlnevek átvehetők paraméterként
//legnagyobb méretű mexikói kaktusz meghatározása
void Feladat(const string& fname,const string& honnan,const string& szine){
    //Objetumok létrehozása


    //Megoldó algoritmus
    bool l=false;
    //kaktusz dx,elem;
    //Status sx;
    //x.read(sx,dx);
    /*while(sx==norm)
    {
         if(dx.haza!=honnan)
         {
         }else if(dx.haza == honnan && l){
            if(dx.meret>elem.meret)
            {
                elem=dx;
            }
            y1.write(dx);
         }else if(dx.haza == honnan && !l)
         {
             l=true; elem=dx;
             y1.write(dx);
         }
         if(dx.szin == szine){
            y2.write(dx);
         }
         x.read(sx,dx);
    }
    if(l)
    {
        cout<<"Legnagyobb "<<honnan<<"-bol szarmazo kaktusz:"<<elem.nev<<endl;
    }else{
        cout<<"Nem volt "<<honnan<<"-bol szarmazo kaktusz.\n";
    }*/
}


