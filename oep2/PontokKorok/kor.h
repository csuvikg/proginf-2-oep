#ifndef KOR_H_INCLUDED
#define KOR_H_INCLUDED
#include <iostream>
#include <fstream>
#include "Pont.h"
#define PI 3.14159265

class Kor {
private:
    Pont kp;
    double r;
    double tavolsag(const Pont&) const;
public:
    enum KorHiba {
        HibasSugar
    };
    Kor(): r(0) {}
    Kor(double a, double b, double c) throw (KorHiba): kp(a, b), r(c) {
        if (c < 0) throw HibasSugar;
    }
    Kor(const Pont& p, double c) throw (KorHiba): kp(p), r(c) {
        if (c < 0) throw HibasSugar;
    }
    double Terulet() const { return r*r*PI; }
    bool RajtaVane(const Pont&) const;
    friend std::ostream& operator<<(std::ostream&, const Kor&);
    friend std::ifstream& operator>>(std::ifstream&, Kor&);
    Kor operator*(double q) const throw(KorHiba);
    Kor operator*=(double q) throw(KorHiba);
    friend Kor operator*(double q, const Kor&) throw (KorHiba);
    bool operator==(const Kor&);
    friend bool operator> (const Kor &k1, const Kor &k2);
};

#endif // KOR_H_INCLUDED
