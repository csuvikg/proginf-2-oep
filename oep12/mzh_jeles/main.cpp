#include <iostream>
#include "myClasses.hpp"

using namespace std;

int main()
{
    string fname;
    cout<<"Add meg az input fajl nevet:"; cin>>fname;
    try{
        BestStudent pr;
        StudentEnumerator enor(fname);
        pr.addEnumerator(&enor);

        pr.run();

        if(pr.found()){
            cout.setf(ios::fixed);
            cout << "A legjobb diak " << pr.optElem().name << ", akinek az atlaga: " << pr.opt() << endl;
        }else cout << "Ures a fajl!\n";
    }catch(SeqInFileEnumerator<Line>::Exceptions err)
    {
        if(err==SeqInFileEnumerator<Line>::OPEN_ERROR)
        {
            cout<<"Nem letezo input fajl:"<<fname<<endl;
        }else{
            cout<<"Nem lehet ilyen hiba!\n";
        }
    }
    return 0;
}


