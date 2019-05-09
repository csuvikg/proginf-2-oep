#pragma once
#include <sstream>
#include "library/seqinfileenumerator.hpp"
#include "library/stringstreamenumerator.hpp"
#include "library/maxsearch.hpp"
#include "library/summation.hpp"

struct Student {
    std::string name;
    double avr;

    friend std::istream& operator>>(std::istream& inp, Student &s);
};


class BestStudent : public MaxSearch<Student, double> {
protected:
    double func(const Student& e) const override { return e.avr; }
};



struct Result {
    double sum;
    int count;
    Result(){}
    Result(double s, int c): sum(s), count(c) {}
};

class Average : public Summation<int, Result> {
protected:
    Result func(const int& e) const override { return Result(double(e), 1); }
    Result neutral() const override { return Result(0.0, 0); }
    Result add(const Result& a, const Result& b) const override {
        return Result(a.sum + b.sum, a.count + b.count);
    }
};



std::istream& operator>>(std::istream& inp, Student &s) {
    std::string line;
    getline(inp, line);
    std::stringstream is(line);
    is >> s.name;

    Average pr;
    StringStreamEnumerator<int> enor(is);
    pr.addEnumerator(&enor);
    pr.run();

    s.avr = pr.result().count > 0 ? pr.result().sum / pr.result().count : 0.0;
    return inp;
}
