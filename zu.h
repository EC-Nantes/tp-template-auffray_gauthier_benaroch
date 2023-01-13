#ifndef ZU_H
#define ZU_H

#include <string>
#include "parcelle.h"
#include "constructible.h"

class zu_t : public Parcelle_t, public Constructible_t {
private:
    float surfaceConstruite;
public:
    zu_t(int, std::string, Polygone_t<int>, float);
    void setSurfaceConstruite(const float f);
    float getSerfaceConstruite() const {return surfaceConstruite;}
    void setType();
    float surfaceConstructible();
};

#endif