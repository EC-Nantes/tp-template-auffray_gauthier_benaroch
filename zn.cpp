#include "zn.h"

zn_t::zn_t(int num, std::string p, Polygone_t<int> f) : Parcelle_t(num, p, f) {
    type = typeParcelle::naturelleForestiere;
    this->setType();
}

void zn_t::setType() {
    type = typeParcelle::naturelleForestiere;
    typeString = "ZN";
}

std::ostream& operator<<(std::ostream& o, const zn_t& parc) {
    o << "Parcelle n°" << parc.getNumero() << " :\n\t";
    o << "Type : " << parc.getType() << "\n\t";
    o << "Polygone : " << parc.forme << "\n\t";
    o << "Propriétaire : " << parc.getProprio() << "\n\t";
    o << "Surface : " << parc.getSurface() << "\n\t";
    o << "Constructible : " << parc.getPconstructible() << " Non constructible !";
    o << std::endl;
    return o;
}