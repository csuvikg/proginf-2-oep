#include <iostream>
#include "infile.h"

using namespace std;

int main()
{
    cout << "Elemek gyakorisaga egyedi felsoroloval\n";
    string fname;
    bool ujra;
    char c;
    do{

        cout<<"\nFutassuk ujra (i/I = igen, minden mas nem): "; cin>>c;
        ujra=c=='i' || c=='I';
    }while(ujra);

    return 0;
}
