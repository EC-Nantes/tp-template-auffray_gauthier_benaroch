#ifndef ZA_H
#define ZA_H

#include <string>
#include "parcelle.h"

class za_t : public Parcelle_t{
private:
    std::string typeCulture;
public:
    za_t(int, std::string, Polygone_t<int>, std::string);
    void setType();
};

#endif