#ifndef ZU_H
#define ZU_H

#include <iostream>
#include <ostream>
#include <streambuf>
#include <cstdlib>
#include <fstream>
#include <string>
#include "parcelle.h"
#include "constructible.h"

class zu_t : public Parcelle_t, public Constructible_t {
private:
    float surfaceConstruite;
public:
    zu_t(int, std::string, Polygone_t<int>, float);                 // constructor
    zu_t(int, std::string, Polygone_t<int>, float, int);
    void setType();                                                 // setters
    void setSurfaceConstruite(const float f);
    float getSurfaceConstruite() const {return surfaceConstruite;}  // getters
    float surfaceConstructible() const;
    std::string print() const;
    friend std::ostream& operator<<(std::ostream&, const zu_t&);    // friend
};

#endif