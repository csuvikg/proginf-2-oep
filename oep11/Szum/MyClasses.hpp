#pragma once
#include "library/summation.hpp"
#include "library/linsearch.hpp"
#include "library/intervalenumerator.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

//Egészek összeadása
class Sum : public Summation<int> {
protected:
    int neutral() const override { return 0; }
    int add(const int& a, const int& b) const override { return a + b; }
    int func(const int& e) const override { return e; }
};

//Egészek összeszorzása (faktoriális)
class Fact : public Summation<int, long long> {
protected:
    long long neutral() const override { return 1; }
    long long add(const long long& a, const long long& b) const override { return a * b; }
    long long func(const int& e) const override { return (long long) e; }
};


//Párosak kiválogatása output streambe (képernyő és fájl is lehet)
class Assortment : public Summation<int, std::ostream> {
public:
    Assortment(std::ostream* o): Summation<int, std::ostream>::Summation(o) {}
protected:
    bool cond(const int& e) const override { return e%2 == 0; }
    std::string func(const int& e) const override {
        std::ostringstream os;
        os << e << " ";
        return os.str();
    }
};

//Párosak kiválogatása vektorba
//Új vektort hoz létre, vagy létező vektorhoz hozzáfűz
class Assortment_vec : public Summation<int, std::vector<int> >{
public:
    Assortment_vec(const std::vector<int>& x): Summation<int, std::vector<int> >::Summation(x) {}
    Assortment_vec() {}
protected:
    int func(const int& e) const override { return e; }
    bool cond(const int& e) const override { return e%2 == 0; }
};

//Minden elem páros-e?
class OptLinKer : public LinSearch<int, true> {
protected:
    bool cond(const int& e) const override { return e%2 == 0; }
};

//Egy egész szám prím-e
class PrimE : public LinSearch<int, true> {
protected:
    int _n;
    bool cond(const int& e) const override { return _n%e != 0; }
public:
    PrimE(const int e): _n(e) {}
};

//Van-e prím szám a fájlban
class PrimKer : public LinSearch<int, false> {
protected:
    bool cond(const int& e) const override {
        if (e < 2) return false;
        PrimE pr(e);
        IntervalEnumerator enor(2, sqrt(e));
        pr.addEnumerator(&enor);
        pr.run();
        return pr.found();
    }
};
