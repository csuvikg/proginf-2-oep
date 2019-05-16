#include <iostream>
#include "library/enumerator.hpp"
#include "library/linsearch.hpp"
#include "library/maxsearch.hpp"
#include "library/counting.hpp"
#include "library/seqinfileenumerator.hpp"
#include "library/stringstreamenumerator.hpp"

/// Input f�jl szerkezete:
/// a f�jl egy sora egy hallgat� �ltal egy t�rgyb�l a megszerzett jegyeket �rja le:
/// hallgat� neve (egy sz�k�z�k n�lk�li string), t�rgy neve (egy sz�k�z�k n�lk�li string)
///      majd a jegyek:(komment,jegy) p�rosok k�vetkeznek, p�ld�ul:
/// Aladar OEP 1pzh 2 1gzh 1 2pzh 4 2gzh 5 bead 5
///
/// egy hallgat�hoz t�bb t�rgy is tartozik
/// a f�jl hallgat�k szerint rendezett

/// K�rd�s: Melyik hallgat� v�gezte el a legkevesebb t�rgyat (akkor v�gzett el egy t�rgyat, ha minden jegye legal�bb 2)?
/// Terv: soron bel�l optimista eld�nt�s: minden jegy legal�bb 2
/// Egyedi felsorol� megsz�molja a hallgat� ezen sorait (sz�ml�l�s)
/// Ezen az egyedi felsorol�n egy minimum keres�s kiv�lasztja a minimumot.

using namespace std;

struct Mark
{
    string comment;
    int grade;
    friend istream& operator>>(istream &is, Mark &m)
    {
        is >> m.comment >> m.grade;
        return is;
    }
};

class CoursePass : public LinSearch<Mark,true>
{
    bool cond(const Mark& e) const override { return e.grade >= 2; }
};

struct Line
{
    string name;
    string course;
    bool passed;
    friend istream& operator>>(istream &is, Line &line);
};

istream& operator>>(istream &is, Line &line)
{
    string str;
    getline(is, str);
    stringstream ss(str);
    ss >> line.name >> line.course;
    CoursePass pr;
    StringStreamEnumerator<Mark> enor(ss);
    pr.addEnumerator(&enor);
    pr.run();
    line.passed = pr.found();
    return is;
}

class countPassed : public Counting<Line>
{
private:
    string _name;
public:
    countPassed(const string &name) : _name(name) {}
protected:
    bool cond(const Line& e) const override { return e.passed; }
    bool whileCond(const Line &e) const override { return e.name == _name; }
    void first() override {}
};

struct Student
{
    string name;
    int noOfPassed;
};

class StudentEnumerator : public Enumerator<Student>
{
private:
    SeqInFileEnumerator<Line>* _f;
    Student _student;
    bool _end;
public:
    StudentEnumerator(const string &fname) { _f = new SeqInFileEnumerator<Line>(fname); }
    ~StudentEnumerator() { delete _f; }
    void first() override { _f->first(); next(); }
    void next() override;
    Student current() const override { return _student; }
    bool end() const override { return _end; }
};

void StudentEnumerator::next()
{
    if (_end = _f->end()) return;
    _student.name = _f->current().name;
    countPassed pr(_student.name);
    pr.addEnumerator(_f);
    pr.run();
    _student.noOfPassed = pr.result();
}

class minPassing : public MaxSearch<Student,int,Less<int>>
{
    virtual int func(const Student& e) const override { return e.noOfPassed; }
};

int main()
{
    try
    {
        minPassing pr;
        StudentEnumerator enor("input.txt");
        pr.addEnumerator(&enor);
        pr.run();
        cout << "Legkevesebb kurzust teljesito diak: "<< pr.optElem().name <<" ("<<pr.opt()<<" kurzus).\n";
    }
    catch (SeqInFileEnumerator<Line>::Exceptions exc)
    {
        cout << "A fajl nem talalhato.\n";
    }
    return 0;
}
