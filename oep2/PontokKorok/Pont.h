#ifndef PONT_H_INCLUDED
#define PONT_H_INCLUDED
#include <iostream>

class Pont
{
private:
    double x,y;
public:
    //Konstruktorok a ponthoz
    Pont() {x=0;y=0;}
    Pont(double a,double b) {x=a;y=b;}
    //Pont() : x(0),y(0) {}
    //Pont(double a, double b): x(a), y(b) {}
    //Pont(double a=0,double b=0): x(a), y(b) {}
    double GetX() const {return x;}
    double GetY() const {return y;}
    void SetX(double a) {x=a;}
    void SetY(double a) {y=a;}
    void SetXY(double a, double b) {x=a; y=b;}
    void Kiir() const {std::cout<<"("<<x<<","<<y<<")";}
    //Destruktor most nem kell, de ha kíváncsiak vagyunk hol hívja meg a fordítóprogram, próbáljuk ki:
    //~Pont() {std::cout<<x<<" "<<y<<" pont megszunt\n";}
};


#endif // PONT_H_INCLUDED
