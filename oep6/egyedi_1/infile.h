#pragma once

#include <fstream>
#include <string>

enum Status{abnorm,norm};

//Szekvenci�lis input f�jl
class InFile{
public:
    enum Errors{MISSINGFILE};
    InFile(const std::string& fname);
    void read(Status &sx, int &dx);
private:
    std::ifstream f;
};

