#include "zau.h"
#include <iostream>
#include <cstdlib>

zau_t::zau_t(int num, std::string p, Polygone_t<int> f) : Parcelle_t(num, p, f) {
    pConstructible = (rand() % 100) + 1;
    this->setType();
}

void zau_t::setType() {
    type = typeParcelle::aUrbaniser;
    typeString = "ZAU";
}

float zau_t::surfaceConstructible() const {
    return (this->getSurface() * pConstructible) / 100;
}

std::ostream& operator<<(std::ostream& o, const zau_t& parc) {
    o << "Parcelle num " << parc.getNumero() << " :\n\t";
    o << "Type : " << parc.getType() << "\n\t";
    o << "Polygone : " << parc.forme << "\n\t";
    o << "Proprietaire : " << parc.getProprio() << "\n\t";
    o << "Surface : " << parc.getSurface() << "\n\t";
    o << "Constructible : " << parc.getPconstructible() << " %\n\t";
    o << "Surface a construire restante : " << parc.surfaceConstructible() << std::endl;
    return o;
}