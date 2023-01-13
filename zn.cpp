#include "zn.h"

zn_t::zn_t(int num, std::string p, Polygone_t<int> f) : Parcelle_t(num, p, f) {
    pConstructible = 0;
    type = typeParcelle::naturelleForestiere;
}

void zn_t::setType() {
    type = typeParcelle::naturelleForestiere;
}