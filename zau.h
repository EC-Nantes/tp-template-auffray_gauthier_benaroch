#ifndef ZAU_H
#define ZAU_H

#include <string>
#include "parcelle.h"
#include "constructible.h"

class zau_t : public Parcelle_t, public Constructible_t {
public:
    zau_t(int, std::string, Polygone_t<int>);
    void setType();
    float surfaceConstructible();
};

#endif
