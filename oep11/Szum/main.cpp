#include <iostream>
#include <fstream>
#include <vector>
#include "MyClasses.hpp"
#include "library\seqinfileenumerator.hpp"
#include "library\intervalenumerator.hpp"
//Feladatok:
//1. Számítsuk ki egy szöveges állományban elhelyezett egész számok összegét
//2. Számítsuk ki egy természetes szám faktoriálisát
//3-4-5. Válogassuk ki egy szoveges állományban elhelyezett számok közül a párosakat (képernyöre, vektorba, output fájlba)
//6. Igaz-e, hogy a fájlban az összes szám páros?
//7. Van-e a fájlban prím szám, ha igen, adjuk meg az elsőt.
//Szorgalmi hf:
//8. Legnagyobb szám a fájlban
//9. Legnagyobb prím szám a fájlban

using namespace std;

void Osszeg();
void Faktorialis();
void Kivalogat(); //Képernyõre
void Kivalogat_vec(); //vektorba
void Kivalogat_fajl(); //Output fajlba
void MindParos();
void VanPrim();
void Legnagyobb();
void LegnagyobbPrim();

int main()
{
    int v;
    do
    {
        cout<<"\nMenu:\n";
        cout<<"0. Kilepes\n";
        cout<<"1. Fajlban levo egeszek osszege.\n";
        cout<<"2. Termeszetes szamok faktorialisa.\n";
        cout<<"3. Fajlban levo parosak kivalogatasa kepernyore.\n";
        cout<<"4. Fajlban levo parosak kivalogatasa vektorba.\n";
        cout<<"5. Fajlban levo parosak kivalogatasa output fajlba.\n";
        cout<<"6. Igaz-e, hogy a fajlban levo osszes szam paros.\n";
        cout<<"7. Van-e a fajlban primszam.\n";
        cout<<"8. Legnagyobb szam a fajlban.\n";
        cout<<"9. Legnagyobb prim szam a fajlban.\n";
        cout<<"\nMelyiket valasztod:"; cin>>v;
        switch(v)
        {
        case 1:
            Osszeg();
            break;
        case 2:
            Faktorialis();
            break;
        case 3:
            Kivalogat();
            break;
        case 4:
            Kivalogat_vec();
            break;
        case 5:
            Kivalogat_fajl();
            break;
        case 6:
            MindParos();
            break;
        case 7:
            VanPrim();
            break;
        case 8:
            Legnagyobb();
            break;
        case 9:
            LegnagyobbPrim();
            break;
        default:
            cout<<"Viszontlatasra\n";
            break;
        }
    }while(v!=0);
    return 0;
}

void Osszeg()
{
    cout << "\nOsszegzes, seqInfile" << endl;
    string fname;
    cout<<"Kerem a fajl nevet:"; cin>>fname;

    Sum pr;
    SeqInFileEnumerator<int> enor(fname);
    pr.addEnumerator(&enor);
    pr.run();

    cout << "Osszeg: " << pr.result() << endl;
}

void Faktorialis()
{
    cout<<"\nOsszegzes, interval"<<endl;
    int n;
    cout<<"Meddig szamitsuk ki a faktorialisokat (20-ig pontos):"; cin>>n;
    for(int i=1; i<=n; ++i){
        Fact pr;
        IntervalEnumerator enor(2, i);
        pr.addEnumerator(&enor);
        pr.run();
        cout << i << "!=" << pr.result() << endl;
    }
}

void Kivalogat()
{
    cout << "\nOsszegzes, seqInfile cout" << endl;
    string fname;
    cout<<"Kerem a fajl nevet:"; cin>>fname;
    try
    {
        SeqInFileEnumerator<int> enor(fname);
        Assortment pr(&cout);
        pr.addEnumerator(&enor);
        cout << fname << " fajlbol a paros szamok:\n";
        pr.run();
        cout << endl;
    }catch(...){
        cerr<<fname<<" fajl nem nyithato meg!\n";
    }
}

void Kivalogat_vec()
{
    cout << "\nOsszegzes, seqInfile vector" << endl;
    string fname;
    cout<<"Kerem a fajl nevet:"; cin>>fname;
    try
    {
        SeqInFileEnumerator<int> enor(fname);
        Assortment_vec pr;
        pr.addEnumerator(&enor);
        pr.run();
        vector<int> x = pr.result();
/*
        vector<int> x;
        x.push_back(-1);
        Assortment_vec pr(x);
        pr.addEnumerator(&enor);
        pr.run();
        x = pr.result();
*/
        cout<<fname<<" fajlbol a paros szamok:\n";
        for(int e : x)
        {
            cout<<e<<" ";
        }
        cout<<endl;
    }catch(...){
        cerr<<fname<<" fajl nem nyithato meg!\n";
    }
    return;
}

void Kivalogat_fajl()
{
    cout << "\nOsszegzes, seqInfile seqOutfile" << endl;
    string fname;
    cout<<"Kerem a bemenet fajl nevet:"; cin>>fname;
    try
    {
        SeqInFileEnumerator<int> enor(fname);
        ofstream f("output.txt");
        Assortment pr(&f);
        pr.addEnumerator(&enor);
        pr.run();
        cout<<"output.txt fajl elkeszult.\n";
    }catch(SeqInFileEnumerator<int>::Exceptions err){
        if(err==SeqInFileEnumerator<int>::OPEN_ERROR)
            cerr<<fname<<" fajl nem nyithato meg!\n";
    }
    return;
}

void MindParos()
{
    cout << "\nOptlinker, seqInfile" << endl;
    string fname;
    cout<<"Kerem a bemenet fajl nevet:"; cin>>fname;
    try
    {
        SeqInFileEnumerator<int> enor(fname);
        OptLinKer pr;
        pr.addEnumerator(&enor);
        pr.run();
        if (pr.found()) {
            cout << "Mind paros\n";
        } else {
            cout << "Nem mind paros, peldaul: " << pr.elem() << endl;
        }
    }catch(...){
        cerr<<fname<<" fajl nem nyithato meg!\n";
    }
    return;
}

void VanPrim()
{
    cout << "\nLinkerben, optlinker" << endl;
    string fname;
    cout<<"Kerem a bemenet fajl nevet:"; cin>>fname;
    try
    {
        SeqInFileEnumerator<int> enor(fname);
        PrimKer pr;
        pr.addEnumerator(&enor);
        pr.run();
        if(pr.found())
        {
            cout<<"Van prim: "<<pr.elem()<<endl;
        }else{
            cout<<"Nincs prim a fajlban.\n";
        }
    }catch(...){
        cerr<<fname<<" fajl nem nyithato meg!\n";
    }
    return;
}

void Legnagyobb()
{
    return;
}

void LegnagyobbPrim()
{
    return;
}
