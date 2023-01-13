#include "zau.h"
#include <iostream>

zau_t::zau_t(int num, std::string p, Polygone_t<int> f) : Parcelle_t(num, p, f) {
    type = typeParcelle::aUrbaniser;
}

void zau_t::setType() {
    type = typeParcelle::aUrbaniser;
}

float zau_t::surfaceConstructible() {
    return (forme.getSurface() * pConstructible) / 100;
}
