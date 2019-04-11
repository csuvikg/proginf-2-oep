#include "department.h"
#include <fstream>

Department::Department(const std::string &fnev)
{
    std::ifstream f;
    f.open(fnev.c_str());
    if(f.fail()) throw FileError;
    int i;
    std::string s;
    while (f >> s >> i) {
        _stock.push_back(new Product(s,i));
    }
    f.close();
}

void Department::takeOutFromStock(int ind)
{
    _stock[ind] = _stock[_stock.size()-1];
    _stock.pop_back();
}


