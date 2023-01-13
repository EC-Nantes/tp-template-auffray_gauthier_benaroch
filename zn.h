#ifndef ZN_H
#define ZN_H

#include <string>
#include "parcelle.h"

class zn_t : public Parcelle_t{
public:
    zn_t(int, std::string, Polygone_t<int>);
    void setType();
};

#endif