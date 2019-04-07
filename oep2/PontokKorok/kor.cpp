#include "kor.h"
#include <cmath>

using namespace std;

double Kor::tavolsag(const Pont& p) const {
    return sqrt(pow(kp.GetX() - p.GetX(), 2) + pow(kp.GetY() - p.GetY(), 2));
}

bool Kor::RajtaVane(const Pont& p) const {
    double d = tavolsag(p);
    return d <= r;
}

ostream& operator<<(ostream& out, const Kor& k) {
    out << "kor adatai: kp=(" << k.kp.GetX() << "," << k.kp.GetY() << ") r=" << k.r << endl;
    return out;
}

ifstream& operator>>(ifstream& in, Kor& k) {
    double a, b;
    in >> a >> b >> k.r;
    if (k.r < 0) throw Kor::HibasSugar;
    k.kp.SetXY(a, b);

    return in;
}

Kor Kor::operator*(double q) const throw(KorHiba) {
    if (q < 0) throw HibasSugar;
    Kor uj(kp, q*r);
    return uj;
}

Kor Kor::operator*=(double q) throw(KorHiba) {
    if (q < 0) throw HibasSugar;
    r*=q;
    return *this;
}

Kor operator*(double q, const Kor& k) throw (Kor::KorHiba) {
    if (q < 0) throw Kor::HibasSugar;
    return k*q;
}

bool Kor::operator==(const Kor& masik) {
    return this->kp.GetX() == masik.kp.GetX() &&
    this->kp.GetY() == masik.kp.GetY() &&
    this->r == masik.r;
}

bool operator>(const Kor &k1, const Kor &k2) {
    return (k1.tavolsag(k2.kp) + k2.r) < k1.r;
}
