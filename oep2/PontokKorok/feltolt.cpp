#include <iostream>
#include <fstream>
#include "feltolt.h"

using namespace std;

void feltoltPont(std::vector<Pont>& p, const std::string& fname) throw (feltoltHiba)
{
    ifstream inp;
    inp.open(fname.c_str());
    if (inp.fail()) throw hibasFajlnev;
    p.clear();
    double x,y;
    while(inp>>x>>y)
    {
        Pont t(x,y);
        p.push_back(t);
    }
    cout<<"A beolvasott pontok ("<<p.size()<<" darab):\n";
    for(int i=0; i<(int)p.size(); ++i)
    {
        p[i].Kiir();
        cout<<endl;
    }
    inp.close();
}

void feltoltKor(std::vector<Kor>& k, const std::string& fname) throw (feltoltHiba,Kor::KorHiba)
{
    ifstream inp;
    inp.open(fname.c_str());
    if (inp.fail()) throw hibasFajlnev;
    k.clear();
    try{
        Kor tmp;
        while(inp>>tmp)
        {
            k.push_back(tmp);
        }
    }catch(Kor::KorHiba err)
    {
            throw err;
    }
    cout<<"A beolvasott korok ("<<k.size()<<" darab):\n";
    for(int i=0; i<(int)k.size(); ++i)
    {
        cout<<i+1<<". "<<k[i];
    }
    cout<<endl;
    inp.close();
}
