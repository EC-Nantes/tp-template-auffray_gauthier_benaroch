#include "parcelle.h"

Parcelle_t::Parcelle_t(int num, std::string p, Polygone_t<int> f) {
    numero = num;
    proprio = p;
    forme.setSommets(f.getSommets());
    surface = f.getSurface();
    if(surface <= 0) {
        ExceptionSurface_t e;
        throw e;
    }
    // TO DO : Exception si forme pas correcte
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
    o << "Parcelle num " << parc.getNumero() << " :\n\t";
    o << "Type : " << parc.getType() << "\n\t";
    o << "Polygone : " << parc.forme << "\n\t";
    o << "Proprietaire : " << parc.getProprio() << "\n\t";
    o << "Surface : " << parc.getSurface() << "\n\t";
    o << "Constructible : " << parc.getPconstructible() << " %" << std::endl;
    return o;
}