#pragma once
#include <sstream>
#include "library/enumerator.hpp"
#include "library/maxsearch.hpp"
#include "library/summation.hpp"
#include "library/seqinfileenumerator.hpp"

struct Student {
    std::string name;
    double avr;
};

class BestStudent : public MaxSearch<Student,double> {
protected:
    double func(const Student &e) const override { return e.avr; }
};

struct Line {
    std::string name;
    int mark;
    friend std::istream& operator>>(std::istream &inp, Line &line);
};

std::istream& operator>>(std::istream &inp, Line &line) {
    std::string l;
    getline(inp, l);
    std::stringstream ss(l);
    ss >> line.name >> line.mark;
    if (ss.fail()) line.mark = 0;
    return inp;
}

class StudentEnumerator : public Enumerator<Student> {
private:
    SeqInFileEnumerator<Line>* _f;
    Student _student;
    bool _end;
public:
    StudentEnumerator(const std::string& fname) {
         _f = new SeqInFileEnumerator<Line>(fname);
    }
    ~StudentEnumerator() {
        delete _f;
    }
    void first() override {
        _f->first();
        next();
    }
    void next() override;
    Student current() const override { return _student; }
    bool end() const override { return _end; }
};


struct Result {
    int sum;
    int count;
    Result(){}
    Result(int a, int b) : sum(a), count(b) {}
};

class Average : public Summation<Line, Result> {
private:
    std::string _name;
public:
    Average(const std::string& name): _name(name) {}
protected:
    Result func(const Line& e) const override { return Result(e.mark, 1); }
    Result neutral() const override { return Result(0, 0); }
    Result add(const Result& a, const Result& b) const override {
        return Result(a.sum + b.sum, a.count + b.count);
    }
    bool whileCond(const Line& e) const override {
        return _name == e.name;
    }
    void first() override {}
};

void StudentEnumerator::next() {
    if (_f->end()) {
        _end = true;
    } else {
        _end = false;
        _student.name = _f->current().name;
        Average pr(_student.name);
        pr.addEnumerator(_f);
        pr.run();
        _student.avr = pr.result().count > 0 ? double(pr.result().sum)/pr.result().count : 0.0;
    }
}
