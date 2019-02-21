#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Felszin {
private:
    vector<int> _t;
    void feltolt1(ifstream&);
    void feltolt2(ifstream&);

public:
    enum Hiba {
        HibasFajlnev,
        HibasAdat
    };

    Felszin(const string& fnev);
    bool legmagasabbHorpadas(int& max, int& ind);
    void tesztkiiras();
};

int main(void) {
    string fnev;
    cout << "Adja meg a fajlnevet: "; cin >> fnev;

    try {
        Felszin f(fnev);

        f.tesztkiiras();

        int max, ind;
        bool l = f.legmagasabbHorpadas(max, ind);
        if (l) {
            cout << "Legmagasabb horpadas: " << max << "\nPozicio: " << ind + 1 << endl;
        } else {
            cout << "Nem volt horpadas.\n";
        }
    } catch (Felszin::Hiba err) {
        switch(err) {
        case Felszin::HibasAdat:
            cerr << "Hibas adat!\n";
            break;
        case Felszin::HibasFajlnev:
            cerr << fnev << " fajl nem nyithato meg!\n";
            break;
        }
    }


    return 0;
}

Felszin::Felszin(const string& fnev) {
    ifstream inp;
    inp.open(fnev.c_str());
    if (inp.fail()) throw HibasFajlnev;
    // feltolt1(inp);
    feltolt2(inp);
    inp.close();
}

void Felszin::feltolt1(ifstream& inp) {
    int n;
    inp >> n;

    _t.resize(n);

    for(int i = 0; i < n; ++i) {
        inp >> _t[i];
        if (inp.fail()) throw HibasAdat;
    }
}

void Felszin::feltolt2(ifstream& inp) {
    _t.clear();
    int e;
    while(inp >> e) {
        _t.push_back(e);
    }

    if (!inp.eof()) throw HibasAdat;
}

void Felszin::tesztkiiras() {
    cout << "Beolvasott adatok:\nn=" << _t.size() << endl;
    for(int e : _t) cout << e << " ";
    cout << endl;
}

bool Felszin::legmagasabbHorpadas(int& max, int& ind) {
    bool l = false;
    for (int i = 1; i < (int) _t.size()-1; ++i) {
        bool f = _t[i+1] > _t[i] && _t[i-1] > _t[i];

        if (!f) {
            continue;
        } else if (f && l && _t[i] > max) {
            max = _t[i];
            ind = i;
        } else {
            l = true;
            max = _t[i];
            ind = i;
        }
    }

    return l;
}
