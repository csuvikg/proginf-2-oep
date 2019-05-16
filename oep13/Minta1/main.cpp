#include <iostream>
#include "library/enumerator.hpp"
#include "library/linsearch.hpp"
#include "library/maxsearch.hpp"
#include "library/counting.hpp"
#include "library/seqinfileenumerator.hpp"
#include "library/stringstreamenumerator.hpp"

/// Input fájl szerkezete:
/// a fájl egy sora egy hallgató által egy tárgyból a megszerzett jegyeket írja le:
/// hallgató neve (egy szóközök nélküli string), tárgy neve (egy szóközök nélküli string)
///      majd a jegyek:(komment,jegy) párosok következnek, például:
/// Aladar OEP 1pzh 2 1gzh 1 2pzh 4 2gzh 5 bead 5
///
/// egy hallgatóhoz több tárgy is tartozik
/// a fájl hallgatók szerint rendezett

/// Kérdés: Melyik hallgató végezte el a legkevesebb tárgyat (akkor végzett el egy tárgyat, ha minden jegye legalább 2)?
/// Terv: soron belül optimista eldöntés: minden jegy legalább 2
/// Egyedi felsoroló megszámolja a hallgató ezen sorait (számlálás)
/// Ezen az egyedi felsorolón egy minimum keresés kiválasztja a minimumot.

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
