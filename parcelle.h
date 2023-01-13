#ifndef PARCELLE_H
#define PARCELLE_H

#include <string>
#include "polygone.h"

class Parcelle_t {
private:
    std::string type;
    int numero;
    std::string proprio;
    float surface;
    Polygone_t<int> forme;
public:
    // constructors
    Parcelle_t(int, std::string, Polygone_t<int>);
    Parcelle_t(Parcelle_t);

    // getters
    int getNumero() {return numero;}
    std::string getProprio() {return proprio;}
    float getSurface() {return surface;}
};

Parcelle_t::Parcelle_t(/* args */) {
}


#endif