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
        try {
            cout << "Add meg az adatfajl nevet: "; cin >> fname;
            FreqEnor t(fname);
            cout << "\nA fajlban szereplo egeszek es gyakorisaguk\n";
            cout << "Ertek\tdb\n";
            for (t.first(); !t.end(); t.next()) {
                cout << t.current().val << "\t" << t.current().db << endl;
            }
        } catch (InFile::Errors err) {
            if (err == InFile::MISSINGFILE) {
                cerr << fname << " fajl nem nyithato meg!\n";
            }
        }

        cout<<"\nFutassuk ujra (i/I = igen, minden mas nem): "; cin>>c;
        ujra=c=='i' || c=='I';
    }while(ujra);

    return 0;
}
