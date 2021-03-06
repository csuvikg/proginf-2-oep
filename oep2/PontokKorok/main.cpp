#include <iostream>
#include <vector>
#include "Pont.h"
#include "Kor.h"
#include "feltolt.h"

using namespace std;

//Feladat:
//Pont �s K�r t�pus megval�s�t�sa oszt�llyal
//Pont: k�t val�s sz�m (a koordin�t�k)
//K�r: egy Pont (a k�z�ppont) �s a sug�r (pozit�v kell legyen)

//Oszt�lyokat tesztel� f�ggv�ny
void Teszt();

//Feladatot megold� f�ggv�ny
void Feladat();

//Feladat: van-e olyan k�r, amelyik mindegyik pontot tartalmazza
bool LinKer(const vector<Kor>&,const vector<Pont>&, int&);
bool OptEldont(const Kor&,const vector<Pont>&);

int main()
{
    cout << "Tipus megvalositas I." << endl;
    // Teszt();
    Feladat();

    return 0;
}

void Teszt()
{
//Pont tesztel�se
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
        //Kor oper�torainak tesztel�se
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
    }catch(Kor::KorHiba err)
    {
        cout<<"Negativ sugaru kort nem lehet letrehozni!\n";
    }


//Pont �s Kor t�pus� vektorok l�trehoz�sa
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

bool LinKer(const vector<Kor>&,const vector<Pont>&, int&) { return true; }
bool OptEldont(const Kor&,const vector<Pont>&) { return true; }
