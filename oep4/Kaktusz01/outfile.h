#ifndef _OUTFILE_KAKTUSZ_H_
#define _OUTFILE_KAKTUSZ_H_
//Szekvenciális output fájl osztálya

#include <string>
#include <fstream>
#include "kaktusz.h"

class OutFile {
public:
    OutFile(const std::string &fileName);
    void write(const Kaktusz &dx);
    ~OutFile() { f.close(); }

    enum Exception {
        FILE_ERROR
    };

private:
    std::ofstream f;
};

#endif // _OUTFILE_KAKTUSZ_H_
