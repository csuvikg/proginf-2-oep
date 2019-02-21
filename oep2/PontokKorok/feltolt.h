#ifndef FELTOLT_H_INCLUDED
#define FELTOLT_H_INCLUDED

#include <vector>
#include <string>
#include "Pont.h"
#include "Kor.h"

enum feltoltHiba{hibasFajlnev};

void feltoltPont(std::vector<Pont>&, const std::string&) throw (feltoltHiba);
void feltoltKor(std::vector<Kor>&, const std::string&) throw (feltoltHiba,Kor::KorHiba);

#endif // FELTOLT_H_INCLUDED
