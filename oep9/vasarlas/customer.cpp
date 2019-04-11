#include <iostream>
#include "customer.h"
#include <fstream>
#include <string>

using namespace std;

Customer::Customer(const string &fname) {
    ifstream f;
    f.open(fname.c_str());
    if (f.fail()) throw FILE_ERROR;
    f >> _name;

    string s;
    while (f>>s) _list.push_back(s);
}

// Javitasi lehetoseg: kivenni a listabol, ha megvette
void Customer::purchase(const Store &store) {
    for (string productName : _list) {
        int ind;
        if (linSearch(productName, store._food, ind)) {
            putInCart(store._food->getProduct(ind));
            store._food->takeOutFromStock(ind);
        }
    }

    for (string productName : _list) {
        int ind;
        if (minSearch(productName, store._technical, ind)) {
            putInCart(store._technical->getProduct(ind));
            store._technical->takeOutFromStock(ind);
        }
    }
}

void Customer::putInCart(Product* product) {
    _basket.push_back(product);
}

bool Customer::linSearch(const string &name, Department* r, int &ind) const {
    bool l = false;
    for (unsigned i = 0; !l && i < r->stockPiece(); ++i) {
        l = (name == r->getProduct(i)->getName());
        ind = i;
    }
    return l;
}

bool Customer::minSearch(const string &name, Department* r, int &ind) const {
    bool l = false;
    int minPrice;
    for (unsigned i = 0; i < r->stockPiece(); ++i) {
        if (r->getProduct(i)->getName() != name) continue;
        else {
            int currentPrice = r->getProduct(i)->getPrice();
            if (l) {
                if (minPrice > currentPrice) {
                    ind = i;
                    minPrice = currentPrice;
                }
            } else {
                l = true;
                ind = i;
                minPrice = currentPrice;
            }
        }
    }
    return l;
}

ostream &operator<< (ostream &os, const Customer &c) {
    os << c._name << " purchased:\n";
    int total = 0;
    for (Product* p : c._basket) {
        os << p->getName() << "\t\t" << p->getPrice() << endl;
        total += p->getPrice();
    }
    os << "------------------------------------\n";
    os << "Total:\t\t" << total << endl;
    return os;
}

