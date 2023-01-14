#include "parcelle.h"

Parcelle_t::Parcelle_t(int num, std::string p, Polygone_t<int> f) {
    numero = num;
    proprio = p;
    forme.setSommets(f.getSommets());
    surface = f.getSurface();
}

Parcelle_t::Parcelle_t(Parcelle_t& parc) {
    numero = parc.getNumero();
    proprio = parc.getProprio();
    forme.setSommets(parc.getForme().getSommets());
}

void Parcelle_t::setForme(Polygone_t<int> f) {
    forme.setSommets(f.getSommets());
    surface = f.getSurface();
}

std::ostream& operator<<(std::ostream& o, const Parcelle_t & parc) {
    o << "Parcelle n°" << parc.getNumero() << " :\n\t";
    o << "Type : " << parc.getType() << "\n\t";
    o << "Polygone : " << parc.forme << "\n\t";
    o << "Propriétaire : " << parc.getProprio() << "\n\t";
    o << "Surface : " << parc.getSurface() << "\n\t";
    o << "Constructible : " << parc.getPconstructible() << " %" << std::endl;
    return o;
}