#include <iostream>
#include <vector>
#include "Pont.h"
#include "kor.h"
#include "feltolt.h"

using namespace std;

//Feladat:
//Pont és Kör típus megvalósítása osztállyal
//Pont: két valós szám (a koordináták)
//Kör: egy Pont (a középpont) és a sugár (pozitív kell legyen)

//Osztályokat tesztelõ függvény
void Teszt();

//Feladatot megoldó függvény
void Feladat();

//Feladat: van-e olyan kör, amelyik mindegyik pontot tartalmazza
bool LinKer(const vector<Kor>&,const vector<Pont>&, int&);
bool OptEldont(const Kor&,const vector<Pont>&);

//Feladat: Van-e a körök között kett?, melyre az a>b teljesül, ha igen melyek ezek a körök?
bool findTwoGreaterCirclesThan(const Kor& kor, const vector<Kor>& korok, vector<int> &foundInd);

int main()
{
    cout << "Tipus megvalositas I." << endl;
    Teszt();
    // Feladat();

    return 0;
}

void Teszt()
{
//Pont tesztelése
    cout<<"***** Pont teszteles\n";
    Pont p1;
    Pont p2(1.2,-3.5);
    cout<<"p1=("<<p1.GetX()<<","<<p1.GetY()<<")\n";
    cout<<"p2="; p2.Kiir(); cout<<endl;
    p1.SetXY(-1,0);
    cout<<"p1="; p1.Kiir(); cout<<endl;
    //Pont p3(.1);
    //cout<<"p3="; p3.Kiir(); cout<<endl;

//Kor tesztelese
    cout<<"\n***** Kor teszteles\n";
    try{
        Kor k1;
        cout<<"k1 "<<k1<<endl;
        Kor k2(1,1,5);
        cout<<"k2 "<<k2<<endl;
        Kor k3(p2,1);
        cout<<"k3 "<<k3<<endl;
        //Kor k4(p2,-3);
        //k2,p1 rajta van
        //k3, p1 nincs rajt
        if(k2.RajtaVane(p1))
            cout<<"Rajta van\n";
        else
            cout<<"Nincs rajta\n";
        //Kor operátorainak tesztelése
        cout<<"\nOperatorok tesztelese:\n";
        k1=k2*2;
        cout<<"k1=k2*2\n";
        cout<<"k1 "<<k1<<endl;
        k2*=0.5;
        cout<<"k2*=0.5\n";
        cout<<"k2 "<<k2<<endl;
        //k2*=-1;
        k1=3*k2;
        cout<<"k1=3*k2\n";
        cout<<"k1 "<<k1<<endl;

        //Egyenlo operator tesztelese
        cout<<"k1==k2\n";
        cout<<(k1==k2 ? "egyenlok" : "nem egyenlok") << endl << endl;
        k1=Kor(k2);
        cout<<"k1=Kor(k2); k1==k2\n";
        cout<<(k1==k2 ? "egyenlok" : "nem egyenlok") << endl << endl;

        //Nagyobb operator tesztelese
        cout<<"k1>k2\n";
        cout<<(k1>k2 ? "nagyobb" : "kisebb vagy egyenlo") << endl << endl;
        k1*=2;
        cout<<"k1*=2; k1>k2\n";
        cout<<(k1>k2 ? "nagyobb" : "kisebb") << endl << endl;

        //hf2: Van-e a körök között kett?, melyre az a>b teljesül, ha igen melyek ezek a körök?
        k1=Kor(1, 1, 6);
        k2=Kor(3, 3, 1);
        k3=Kor(2, 2, 2);
        vector<int> result;
        bool l = findTwoGreaterCirclesThan(k1, {k2, k3}, result);
        cout << "\nVan: " << (l ? "igen" : "nem") << endl;
        if (l) {
            cout << "Indexek: ";
            for (int ind : result) cout << ind + 1 << " ";
            cout << "\n\n";
        }

        result.clear();
        l = findTwoGreaterCirclesThan(k2, {k1, k3}, result);
        cout << "\nVan: " << (l ? "igen" : "nem") << endl;
        if (l) {
            cout << "Indexek: ";
            for (int ind : result) cout << ind + 1 << " ";
            cout << "\n\n";
        }

    }catch(Kor::KorHiba err)
    {
        cout<<"Negativ sugaru kort nem lehet letrehozni!\n";
    }


//Pont és Kor típusú vektorok létrehozása
    vector<Pont> x;
    x.resize(5);
    vector<Kor> y(100);
}

void Feladat()
{
    vector<Pont> p;
    vector<Kor> z;
    string fajlnev;
    bool l1,l2;
    try{
        l1=true;
        cout<<"Adja meg a pontokat tartalmazo fajl nevet:";
        cin>>fajlnev;
        feltoltPont(p,fajlnev);
    }catch(feltoltHiba err)
    {
        cout<<"Nem sikerult "<<fajlnev<<" bemeneti fajl megnyitasa!\n";
        l1=false;
    }
    try{
        l2=true;
        cout<<"Adja meg a koroket tartalmazo fajl nevet:";
        cin>>fajlnev;
        feltoltKor(z,fajlnev);
    }
    catch(feltoltHiba err)
    {
        cout<<"Nem sikerult "<<fajlnev<<" bemeneti fajl megnyitasa!\n";
        l2=false;
    }
    catch(Kor::KorHiba)
    {
        cout<<fajlnev<<" fajlban negativ sugaru kort talaltam!\n";
        l2=false;
    }
    if(l1 && l2){
        //Feladat megoldasa
        bool l; int ind;
        l=LinKer(z,p,ind);
        if(l)
        {
            cout<<ind+1<<". kor tartalmazza valamennyi pontot.\n";
            cout<<z[ind]<<endl;
        }else{
            cout<<"Nincs olyan kor, amelyik az osszes pontot tartalmazza";
        }
    }
}

bool LinKer(const vector<Kor>& korok, const vector<Pont>& pontok, int& ind) {
    bool l = false;
    unsigned i = 0;

    while (!l && i < korok.size()) {
        l = OptEldont(korok[i], pontok);
        ind = i;
        ++i;
    }

    return l;
}

bool OptEldont(const Kor& kor, const vector<Pont>& pontok) {
    bool l = false;
    unsigned i = 0;

    while (!l && i < pontok.size()) {
        l = kor.RajtaVane(pontok[i]);
        ++i;
    }

    return l;
}

bool findTwoGreaterCirclesThan(const Kor& kor, const vector<Kor>& korok, vector<int> &foundInd) {
    if (korok.size() < 2) return false;

    int found = 0;
    unsigned int i = 0;

    while (found < 2 && i < korok.size()) {
        if (kor>(korok[i])) {
            foundInd.push_back(i);
            ++found;
        }
        ++i;
    }

    return found == 2;
}
