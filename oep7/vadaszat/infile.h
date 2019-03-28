#pragma once

//Szekvencialis input fájl nevezetes felsoroloja

#include <fstream>
#include <vector>
#include <string>

enum Status{abnorm,norm};

struct adat{
    std::string id;
    std::string date;
    std::vector<std::string> fajta;
    std::vector<float> suly;
};


class InFile{
public:
    enum Errors{MISSINGFILE};

    InFile(const std::string& fname);
    void read(Status &sx, adat &dx);

private:
    std::ifstream f;
};
