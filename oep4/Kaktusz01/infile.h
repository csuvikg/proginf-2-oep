#ifndef _INFILE_KAKTUSZ_H_
#define _INFILE_KAKTUSZ_H_
//Szekvencialis input fájl osztalya

#include <string>
#include <fstream>
#include "kaktusz.h"

enum Status {
    abnorm,
    norm
};

class InFile {
public:
    enum Exception {
        FILE_ERROR
    };

    InFile(const std::string &fileName);
    // void read(Status &sx, Kaktusz &dx);
    bool read(Status &sx, Kaktusz &dx);

private:
    std::ifstream f;
};

#endif // _INFILE_KAKTUSZ_H_
